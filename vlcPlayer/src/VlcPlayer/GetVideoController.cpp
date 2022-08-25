#include "GetVideoController.h"
#include "Logger.h"
#include "MsgDefine.h"
#include <string.h>
#include <qdebug.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qfile.h>
#include <qjsonarray.h>

GetVideoController::GetVideoController(QObject *parent): QThread(parent)
{
}


void GetVideoController::run()
{

	if (this->lsocket == nullptr) return;
	try
	{
		MsgHeader header;
		header.controlMask = GET_VIDEO;
		header.contentLength = 0;

		char sendBuffer[MSG_HEAD_LEN] = "\0";
		memcpy(sendBuffer, &header, MSG_HEAD_LEN);

		lsocket->Send(sendBuffer, MSG_HEAD_LEN);

		memset(sendBuffer, 0, MSG_HEAD_LEN);
		memset(&header, 0, MSG_HEAD_LEN);

		//接收消息头
		lsocket->Recv(sendBuffer, MSG_HEAD_LEN);

		memcpy(&header, sendBuffer, MSG_HEAD_LEN);

		int contLen = header.contentLength;
		char *recvBuffer = new char[contLen];

		lsocket->Recv(recvBuffer, contLen);

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
	

		//发送完毕
		emit dealOver(res);

		delete recvBuffer;
	}
	catch (const std::exception& e)
	{
		ERROR("get video file Error{}", e.what());
	}
	
}
