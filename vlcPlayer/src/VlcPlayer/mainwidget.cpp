#include "mainwidget.h"
#include "qstringlist.h"
#include "qstringlistmodel.h"
#include "CommonUtils.h"
#include "GetVideoController.h"
#include "MsgDefine.h"
#include <qfiledialog.h>
#include <thread>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonarray.h>
#include "settingutil.h"

#pragma execution_character_set("utf-8")


void MainWidget::ShowPlay(QModelIndex index)
{
	ui.lbPlayTime->setText("0:0:0");
	ui.tbPlayTack->setValue(0);
	if (player->IsPlaying())
	{
		player->StartOrStop();

	}
	player->CutPlay();

	std::string url = playListAddress.at(index.column()).toStdString();

	url = url.substr(url.find_last_of("/"), url.size());
	url = "rtmp://"+ Setting::SERVER_ADDRESS.toStdString() + "/vod" + url;

	player->Start(url, (HWND)ui.frmPlay->winId());
	//player->Start("rtmp://192.168.199.185/vod/test.mp4", (HWND)ui.frmPlay->winId());
	
	totalTimeMs = player->GetTotalTime();
	
	ui.tbPlayTack->setMaximum((int)(totalTimeMs / 1000));
	ui.lbTotalTime->setText(CommonUtils::ConvertTimeShow(totalTimeMs, 1000));
	timer->setInterval(1000);
	timer->start();

}

//��ʱ��
void MainWidget::updateTime()
{

	if (ui.tbPlayTack->value() < ui.tbPlayTack->maximum())
	{
		int value = ui.tbPlayTack->value();
		++value;
		ui.tbPlayTack->setValue(value);
	}

	long time = player->GetNowPlayTime();
	ui.lbPlayTime->setText(CommonUtils::ConvertTimeShow(time, 1000));

	if (player->Status() == PLAYSTATUS::ENDED)
	{
		//�������
		timer->stop();
		player->CutPlay();
	}

}

void MainWidget::RateClick()
{
	if (player == NULL || !player->IsPlaying()) return;

	float now = ui.btnRate->text().toFloat();
	now = RateControl(now);
	player->SetRate(now);
	ui.btnRate->setText(QString("%1").arg(now));
	timer->stop();
	timer->setInterval(1000 / now);
	timer->start();
}

void MainWidget::SliderClick(int value)
{

	if (player == NULL || player->Status() == PLAYSTATUS::ENDED || player->Status() == PLAYSTATUS::CLOSE) return;

	if (player->IsPlaying())
	{
		timer->stop();
		player->SetPlayPos(value * 1000);
	}
	else
	{
		player->SetPlayPos(value * 1000);
		player->StartOrStop();
	}
	
	timer->start();
}

//�ϴ��ļ�
void MainWidget::UPFileClick()
{

	if (fThread == nullptr) return;

	if (fThread->isRunning())
	{
		QMessageBox::warning(NULL, "�ϴ��ļ�ʧ��", "���ļ������ϴ����Ե�....", QMessageBox::StandardButton::Ok);
		return;
	}

	QFileDialog *fileDlg = new QFileDialog();

	fileDlg->setWindowTitle("Please Select UpLoad Video File");
	fileDlg->setDirectory(".");
	fileDlg->setNameFilter(tr("File(*.mp4)"));
	
	//��ȡ�û����ļ�
	QStringList fileNames;
	if (fileDlg->exec()) {
		fileNames = fileDlg->selectedFiles();
		ui.btnStop->setEnabled(true);
		ui.btnCut->setEnabled(true);

		QFileInfo fileInfo(fileNames[0]);
		ui.prbFileUp->setMaximum(fileInfo.size());

		fThread->file = fileNames[0];
		fThread->start();
	}
}

//��ͣ�ϴ��ļ�
void MainWidget::StopUpLoad()
{
}

//ֹͣ�ϴ��ļ�
void MainWidget::CutUpLoad()
{
	if (fThread->isRunning())
	{
		fThread->Pause();
		ui.prbFileUp->setValue(0);
	}
}

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
	setFixedSize(this->width(), this->height());
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowTitleHint);

	player = new NetWorkPlayer();
	ui.tbPlayTack->setTracking(false);
	ui.tbPlayTack->setPageStep(5);


	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &MainWidget::updateTime);
	connect(ui.tbPlayTack, &CustomSlider::costomSliderClicked, this, &MainWidget::SliderClick);

	fThread = new FileProgressThread(this);
	connect(fThread, &FileProgressThread::updateProgress, this, &MainWidget::updateFileUpLoadPro);
	connect(fThread, &FileProgressThread::progressMsg, this, &MainWidget::progressFileUpLoadMsg);

	connect(ui.btnStop, &QPushButton::clicked, fThread, &FileProgressThread::StopOrStart);


	getThread = new GetVideoController(this);
	connect(getThread, &GetVideoController::dealOver, this, &MainWidget::processVideoFileUpdate);

}

MainWidget::~MainWidget()
{
	if (this->socket)
	{
		socket->Close();
		delete socket;
	}

	if (this->player)
	{
		delete player;
	}

	if (timer)
	{
		timer->stop();
		delete timer;
	}
}

void MainWidget::Init(LSocket * sock)
{
	this->socket = sock;
	//getThread->lsocket = socket;
	//getThread->start();
	MsgHeader header;
	header.controlMask = GET_VIDEO;
	header.contentLength = 0;

	char sendBuffer[MSG_HEAD_LEN] = "\0";
	memcpy(sendBuffer, &header, MSG_HEAD_LEN);

	socket->Send(sendBuffer, MSG_HEAD_LEN);

	memset(sendBuffer, 0, MSG_HEAD_LEN);
	memset(&header, 0, MSG_HEAD_LEN);

	//������Ϣͷ
	socket->Recv(sendBuffer, MSG_HEAD_LEN);

	memcpy(&header, sendBuffer, MSG_HEAD_LEN);

	int contLen = header.contentLength;
	char *recvBuffer = new char[contLen];

	socket->Recv(recvBuffer, contLen);

	QList<QMap<QString, QString>> res;

	QByteArray arry = QByteArray(recvBuffer, contLen);

	QJsonArray fileArray = QJsonDocument::fromJson(arry).array();
	for (size_t i = 0; i < fileArray.size(); i++)
	{
		QJsonObject obj = fileArray[i].toObject();

		QMap< QString, QString> map;
		map.insert("FILE_NAME", obj.value("FILE_NAME").toString());
		map.insert("FILE_PATH", obj.value("FILE_PATH").toString());
		res.push_back(map);
	}

	delete recvBuffer;

	processVideoFileUpdate(res);
}

#pragma region �����ƶ�
void MainWidget::mousePressEvent(QMouseEvent * e)
{
	last = e->globalPos();
}

void MainWidget::mouseMoveEvent(QMouseEvent * e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}

void MainWidget::mouseReleaseEvent(QMouseEvent * e)
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}

#pragma endregion

//���½�����
void MainWidget::updateFileUpLoadPro(int num)
{
	ui.prbFileUp->setValue(ui.prbFileUp->value() + num);
}

//�ź�չʾ�ϴ��ļ�����Ϣ
void MainWidget::progressFileUpLoadMsg(bool error, QString msg)
{
	ui.btnStop->setEnabled(false);
	ui.btnCut->setEnabled(false);
	if (error)
	{
		QMessageBox::warning(NULL, "�ϴ��ļ�ʧ��", msg, QMessageBox::StandardButton::Ok);
		ui.prbFileUp->setValue(0);
	}
	else
	{
		QMessageBox::information(NULL, "�ϴ��ļ���ʾ", msg, QMessageBox::StandardButton::Ok);
		ui.prbFileUp->setValue(0);
	}
}

void MainWidget::processVideoFileUpdate(QList<QMap<QString, QString>> res)
{
	QStringList sList;
	for (auto it = res.begin(); it != res.end(); it++)
	{
		sList.append((*it).value("FILE_NAME"));
		playListAddress.append((*it).value("FILE_PATH"));
	}
	QStringListModel *slm = new QStringListModel(this);

	slm->setStringList(sList);
	ui.lstvPlayList->setModel(slm);
	connect(ui.lstvPlayList, SIGNAL(clicked(QModelIndex)), this, SLOT(ShowPlay(QModelIndex)));
}

//��������Ƶ�ٶȿ���
float MainWidget::RateControl(float now)
{
	int index = rateList.indexOf(now);

	if (index <= rateList.size() - 2)
	{
		return rateList[index + 1];
	}
	else
	{
		return rateList[0];
	}
}

void MainWidget::Close()
{
	if (fThread != nullptr)
	{
		if (fThread->isRunning())
		{
			fThread->Pause();
		}
		//�ȴ��߳��˳�
		while (fThread->isRunning())
		{
			QThread::msleep(50);
		}
		delete fThread;
	}

	if (this->getThread != nullptr)
	{
		delete getThread;
	}

	this->close();
}
