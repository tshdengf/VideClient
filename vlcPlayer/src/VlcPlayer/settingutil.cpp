#include "settingutil.h"

QString Setting::SERVER_ADDRESS = "";
qint32 Setting::SERVER_PORT = 0;


void Setting::Init(QString settingFilename)
{
	//³õÊ¼»¯ÍøÂç¿â
	WSADATA ws;
	WSAStartup(MAKEWORD(2, 2), &ws);
	QString file = settingFilename;
	if (settingFilename.isEmpty())
	{
		QDir curPath(QCoreApplication::applicationDirPath());
		curPath.cdUp();
		file = curPath.absolutePath() + QObject::tr("/etc/config.ini");
	}


	QSettings setting(file, QSettings::IniFormat);

	bool flg = setting.contains("Server");

	SERVER_ADDRESS = setting.value("Server/address").toString();
	SERVER_PORT = setting.value("Server/port").toInt();
}