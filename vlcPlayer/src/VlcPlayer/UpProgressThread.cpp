#include "UpProgressThread.h"
#include "MsgDefine.h"
#include "Logger.h"
#include "socket.h"
#include <qfile.h>
#include <qfileinfo.h>
#include <string.h>
#include <qdebug.h>
#include <qcryptographichash.h>
#include <qjsonobject.h>
#include <QDir>
#include <qobject.h>
#include <qjsonarray.h>
#include <qcoreapplication.h>
#include "JsonUtils.h"

#pragma execution_character_set("utf-8")

FileProgressThread::FileProgressThread(QString filePath)
{
	this->file = filePath;
}


FileProgressThread::FileProgressThread(QObject *parent):QThread(parent), stopFlag(false), startFlg(false)
{
}

void FileProgressThread::StopOrStart()
{
	if (FileProgressThread::isRunning())
	{
		if (stopFlag.load() == false)
		{
			stopFlag.store(true);
		}
		else
		{
			stopFlag.store(false);
		}

	}
}

void FileProgressThread::Resume()
{
	if (FileProgressThread::isRunning())
	{
		stopFlag.store(false);
	}
}

void FileProgressThread::Pause()
{
	if (FileProgressThread::isRunning())
	{
		startFlg.store(false);
	}
}

//���½������߳�
void FileProgressThread::run()
{
	startFlg.store(true);
	stopFlag.store(false);

	QFile upFile(file);
	QFileInfo fileInfo(upFile);

	bool isOK = upFile.open(QIODevice::ReadOnly);
	QByteArray ba = QCryptographicHash::hash(upFile.readAll(), QCryptographicHash::Md5);
	auto fileHash = ba.toHex();
	if (isOK)
	{
		INFO("�ϴ��ļ�:{}, �ļ���С:{}", file.toLatin1().data(), (long)fileInfo.size());
		//����һ�������ӷ����ļ�
		LSocket upLoadConn;
		std::string errMsg;
		if (-1 == upLoadConn.TcpConnect(errMsg))
		{
			emit progressMsg(true, "���ӷ�����ʧ��");
			INFO("�ϴ��ļ�{}���ӷ�����ʧ�ܣ�", file.toLatin1().data());
			upFile.close();
			startFlg.store(false);
			return;
		}
		int fileInfoLen = sizeof(FileUpLoadInfo);
		MsgHeader header(fileInfoLen, UPLOAD_FILE);
		FileUpLoadInfo upLoadFileInfo;

		//�ӻ����ж�ȡ��Pos
		long pos = GetCacheSeek(QString(fileHash));
		if (pos == 0)
		{
			//����0������Ƿ�ֹ���ַ�����������д����
			header.controlMask = DELETE_CACHE_FILE;
			memcpy(upLoadFileInfo.fileName, fileInfo.fileName().toStdString().c_str(), file.toStdString().length());
			upLoadFileInfo.fileLen = fileInfo.size();
			strcpy(upLoadFileInfo.md5, fileHash.toStdString().c_str());
			upLoadFileInfo.seekIndex = -1;
			char *buffer = new char[fileInfoLen + MSG_HEAD_LEN];
			memcpy(buffer, &header, MSG_HEAD_LEN);
			memcpy(buffer + MSG_HEAD_LEN, &upLoadFileInfo, fileInfoLen);

			upLoadConn.Send(buffer, MSG_HEAD_LEN + fileInfoLen);
			delete buffer;
		}
		emit updateProgress(pos);
		upFile.seek(pos);

		while (!upFile.atEnd())
		{
			if (stopFlag.load() == true)
			{
				qDebug() << "Thread Stop";
				continue;
			}
			if (startFlg.load() == false)
			{
				qDebug() << "Thread Exit";
				//�˳�ʱ���¼Seek��λ�� ���ڶϵ�����
				RecordFileCache(file, QString(fileHash), upFile.pos());
				return;
			}

			memset(&upLoadFileInfo, 0, fileInfoLen);
			header.controlMask = UPLOAD_FILE;
			//�������ݰ�
			memcpy(upLoadFileInfo.fileName, fileInfo.fileName().toStdString().c_str(), file.toStdString().length());
			upLoadFileInfo.fileLen = fileInfo.size();
			strcpy(upLoadFileInfo.md5, fileHash.toStdString().c_str());
			int realLen = upFile.read(upLoadFileInfo.buffer, 1024); 						//��ȡ�ļ�
			qDebug() << realLen << stopFlag.load();
			upLoadFileInfo.bufferLen = realLen;


			//��������
			char *buffer = new char[fileInfoLen + MSG_HEAD_LEN];
			memcpy(buffer, &header, MSG_HEAD_LEN);
			memcpy(buffer + MSG_HEAD_LEN, &upLoadFileInfo, fileInfoLen);
			if (-1 == upLoadConn.Send(buffer, MSG_HEAD_LEN + fileInfoLen))
			{
				emit progressMsg(true, "Send Error");
				INFO("UP File{} Send Error��", file.toLatin1().data());
				delete buffer;
				upFile.close();
				startFlg.store(false);
				return;
			}
			delete buffer;

			//�ȴ���������Ӧ
			RequestReplay requestReplay;
			char recvBuffer[MSG_HEAD_LEN + sizeof(requestReplay)] = "\0";
			if (upLoadConn.Recv(recvBuffer, MSG_HEAD_LEN + sizeof(requestReplay)) == -1)
			{
				emit progressMsg(true, "Recv Server Up File Msg Error");
				INFO("Recv Server Up File Msg Error");
				upFile.close();
				startFlg.store(false);
				return ;
			}

			//�����������Ϣ
			memcpy(&requestReplay, recvBuffer + MSG_HEAD_LEN, sizeof(requestReplay));
			if (requestReplay.code == 0)
			{
				emit progressMsg(true, "UP File Error" + QString(requestReplay.msg));
				INFO("UP File Error{}", requestReplay.msg);
				upFile.close();
				startFlg.store(false);
				return ;
			}
			//�ϴ��ɹ�
			emit updateProgress(realLen);
			QThread::msleep(50);
		}
		emit progressMsg(false, "UP File Over");

		//���ͷ�����д�뵽���ݿ�
		header.controlMask = UPLOAD_FILE_OVER;
		memcpy(upLoadFileInfo.fileName, fileInfo.fileName().toStdString().c_str(), file.toStdString().length());
		upLoadFileInfo.fileLen = fileInfo.size();
		strcpy(upLoadFileInfo.md5, fileHash.toStdString().c_str());
		upLoadFileInfo.seekIndex = fileInfo.size();
		char *buffer = new char[fileInfoLen + MSG_HEAD_LEN];
		memcpy(buffer, &header, MSG_HEAD_LEN);
		memcpy(buffer + MSG_HEAD_LEN, &upLoadFileInfo, fileInfoLen);
		upLoadConn.Send(buffer, MSG_HEAD_LEN + fileInfoLen);
		delete buffer;

	}
	else
	{
		INFO("�ϴ��ļ�:{} ��ʧ��", file.toLatin1().data());
		upFile.close();
		startFlg.store(false);
		return;
	}
	startFlg.store(false);
}

QString FileProgressThread::GetCacheFile()
{
	QDir curPath(QCoreApplication::applicationDirPath());
	curPath.cdUp();
	QString cacheFile = curPath.absolutePath() + QObject::tr("/etc/upLoad.cache");
	return cacheFile;
}

//��¼�ļ�����λ�����ڶϵ�����
void FileProgressThread::RecordFileCache(QString file, QString md5, long pos)
{

	QJsonArray array = JsonUtils::JsonFromFile(GetCacheFile());

	for (size_t i = 0; i < array.size(); i++)
	{
		QJsonObject obj = array[i].toObject();

		if (obj.value("MD5").toString() == md5)
		{
			array.removeAt(i);
		}
	}


	QJsonObject posJsonObj;
	posJsonObj.insert("File", file);
	posJsonObj.insert("MD5", md5);
	posJsonObj.insert("Pos", pos);

	array.push_back(posJsonObj);

	QString cacheFile = GetCacheFile();
	JsonUtils::JsonObjToFile(array, cacheFile);
}

long FileProgressThread::GetCacheSeek(QString md5)
{
	QJsonArray array = JsonUtils::JsonFromFile(GetCacheFile());

	for (size_t i = 0; i < array.size(); i++)
	{
		QJsonObject obj = array[i].toObject();

		if (obj.value("MD5").toString() == md5)
		{
			return obj.value("Pos").toInt();
		}
	}

	return 0;
}

