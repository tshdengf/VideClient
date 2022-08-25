#include "CommonUtils.h"


QString CommonUtils::localHost = QHostInfo::localHostName();

QString CommonUtils::GetIp(QString localHost)
{
	QString ipAddr;

	QHostInfo info = QHostInfo::fromName(localHost);
	info.addresses();//QHostInfo的address函数获取本机ip地址
	//如果存在多条ip地址ipv4和ipv6：
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol) {//只取ipv4协议的地址
			qDebug() << address.toString();
			ipAddr = address.toString();
		}
	}
	return ipAddr;
	
}

//QString 转换为 char *
char * CommonUtils::QStringToCharPtr(QString str)
{
	QByteArray ba = str.toLocal8Bit();

	return ba.data();
}

QString CommonUtils::ConvertTimeShow(long time, int div)
{
	if (div <= 0) return "";

	long total = time / div;
	long hours;
	long min;
	long second;

	hours = total / 3600;

	if (hours == 0)
	{
		min = total / 60;
		if (min == 0)
		{
			second = total;
		}
		else
		{
			second = total - (min * 60);
		}
	}
	else
	{
		min = (total - hours * 3600) / 60;
		if (min == 0)
		{
			second = total;
		}
		else
		{
			second = (total - (hours * 3600) - (min * 60));
		}
	}

	return QString("%1:%2:%3").arg(hours).arg(min).arg(second);
}
