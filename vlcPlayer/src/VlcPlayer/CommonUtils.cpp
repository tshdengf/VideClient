#include "CommonUtils.h"


QString CommonUtils::localHost = QHostInfo::localHostName();

QString CommonUtils::GetIp(QString localHost)
{
	QString ipAddr;

	QHostInfo info = QHostInfo::fromName(localHost);
	info.addresses();//QHostInfo��address������ȡ����ip��ַ
	//������ڶ���ip��ַipv4��ipv6��
	foreach(QHostAddress address, info.addresses())
	{
		if (address.protocol() == QAbstractSocket::IPv4Protocol) {//ֻȡipv4Э��ĵ�ַ
			qDebug() << address.toString();
			ipAddr = address.toString();
		}
	}
	return ipAddr;
	
}

//QString ת��Ϊ char *
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
