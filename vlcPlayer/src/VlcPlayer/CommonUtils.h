#pragma once

#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QProcess>
#include <qstring.h>

class CommonUtils
{
public:
	//��ȡ����IP
	static QString GetIp(QString localHost);

	static  QString localHost;

	static char * QStringToCharPtr(QString str);

	static QString ConvertTimeShow(long time, int div);



};
