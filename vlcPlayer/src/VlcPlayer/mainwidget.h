#pragma once

#include <QWidget>
#include "ui_mainwidget.h"
#include "socket.h"
#include "qmessagebox.h"
#include "NetWorkPlAYER.h"
#include <qtimer.h>
#include <qlist.h>
#include <QmouseEvent>
#include "UpProgressThread.h"
#include "GetVideoController.h"
#include <qlist.h>
#include <qmap.h>

class MainWidget : public QWidget
{
	Q_OBJECT

public slots:
	void Close();
	void ShowPlay(QModelIndex index);

	void updateTime();

	void RateClick();

	void SliderClick(int value);

	void UPFileClick();

	void StopUpLoad();

	void CutUpLoad();

	void processVideoFileUpdate(QList<QMap<QString, QString>> res);

	void updateFileUpLoadPro(int num);
	void progressFileUpLoadMsg(bool error, QString msg);

public:
	MainWidget(QWidget *parent = Q_NULLPTR);
	~MainWidget();

	void Init(LSocket * sock);

protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
private:
	Ui::mainwidget ui;

	LSocket * socket;

	NetWorkPlayer *player = NULL;

	QTimer* timer = nullptr;

	long totalTimeMs;
	QPoint last;

	QList<float> rateList = { 1.0f, 1.5f, 1.75f, 2.0f };

	QList<QString> playListAddress;

	float RateControl(float now);

	FileProgressThread *fThread = nullptr;
	GetVideoController *getThread = nullptr;

};
