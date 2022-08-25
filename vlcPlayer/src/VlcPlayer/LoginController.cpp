#include "LoginController.h"
#include "CommonUtils.h"
#include "MsgDefine.h"
#include <QString>
#include <string>
#include <qcryptographichash.h>


bool LoginController::Login(QString uName, QString password, QString &error, LSocket** serverConn)
{
	//��������м���
	QString md5Str = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5).toHex();

	//������Ϣ
	QString ip = CommonUtils::GetIp(CommonUtils::localHost);
	LoginInfo info(ip.toLatin1().data(), uName.toLatin1().data(), md5Str.toLatin1().data());
	MsgHeader head(sizeof(info), USER_LOGIN);

	char buffer[MSG_HEAD_LEN + sizeof(info)] = "\0";
	memcpy(buffer, (const void *)&head, MSG_HEAD_LEN);
	memcpy(buffer + MSG_HEAD_LEN, (const void *)&info, sizeof(info));

	//�����ظ�����
	if (*serverConn == nullptr)
	{
		*serverConn = new LSocket();
		std::string connerr;
		if ((*serverConn)->TcpConnect(connerr) == -1)
		{
			error = QString::fromStdString(connerr);
			return false;
		}
	}
	if ((*serverConn)->Send(buffer, MSG_HEAD_LEN + sizeof(info)) == -1)
	{
		error = "Server Error";
		return false;
	}

	//���շ������Ϣ
	VerifyLoginInfo verifyInfo;
	char recvBuffer[MSG_HEAD_LEN + sizeof(verifyInfo)] = "\0";
	if ((*serverConn)->Recv(recvBuffer, MSG_HEAD_LEN + sizeof(verifyInfo)) == -1)
	{
		error = "Recv Server Check Login Msg Error";
		return false;
	}

	//����
	memcpy(&verifyInfo, recvBuffer + MSG_HEAD_LEN, sizeof(verifyInfo));
	if (!verifyInfo.success)
	{
		QString msg = QString((char *)verifyInfo.errorMsg);
		error = "Login Fault: " + msg;
		return false;
	}

	return true;
}
