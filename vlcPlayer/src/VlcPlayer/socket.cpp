#include "socket.h"
#include "settingutil.h"
#include "Logger.h"
#pragma execution_character_set("utf-8")

LSocket::~LSocket()
{
	this->Close();
}

//连接服务端, 返回错误信息
int LSocket::TcpConnect(std::string & error)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		error = "Create Socket Error!";
		return -1;
	}

	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(Setting::SERVER_PORT);
	saddr.sin_addr.s_addr = inet_addr(Setting::SERVER_ADDRESS.toLatin1().data());

	//把套接字设置成非阻塞模式
	unsigned long ul = 1;
	ioctlsocket(sockfd, FIONBIO, &ul);
	fd_set set;
	if (connect(sockfd, (sockaddr *)&saddr, sizeof(saddr)) != 0) 
	{
		//尝试重连
		FD_ZERO(&set);
		FD_SET(sockfd, &set);
		timeval tm;
		tm.tv_sec = 0;
		tm.tv_usec = 1000;
		INFO("Connect server failed, Try to reconnection.....");
		if (select(sockfd + 1, 0, &set, 0, &tm) <= 0)
		{
			error = "Connect Server Error!";
			ul = 0;
			ioctlsocket(sockfd, FIONBIO, &ul);
			INFO("Connect server failed, Try to reconnection.....Failed");
			return -1;
		}
		
	}
	ul = 0;
	ioctlsocket(sockfd, FIONBIO, &ul);
	return sockfd;
}

int LSocket::Send(const char *buf, int sendSize)
{
	int bytes = -1;

	int length = sendSize;
	do
	{
	ReSend:
		bytes = send(sockfd, buf, length, 0);
		if (bytes > 0)
		{
			length -= bytes;
			buf += bytes;
		}
		else if (bytes < 0)
		{
			if (errno == EINTR || errno == EWOULDBLOCK || errno == EAGAIN)
				goto ReSend;

			if (bytes == -1)
			{
				//重连服务端
				int ret = ReConnection();
				if (ret == 1)  goto ReSend;
				else return ret;
	
			}
		}
		else
		{
			int ret = ReConnection();
			if (ret == 1)  goto ReSend;
			else return ret;
		}
	} while (length > 0 && bytes > 0);

	if (length == 0)
		bytes = sendSize;
	return bytes;
}

int LSocket::Recv(char *buf, int recvSize)
{
	int recvLen = 0;
	int nRet = 0;

	while (recvLen < recvSize)
	{
		nRet = recv(sockfd, buf, recvSize - recvLen, 0);
		if (nRet > 0)
		{
			recvLen += nRet;
			buf += nRet;
		}
		else if (nRet < 0)
		{
			if (errno == EAGAIN || errno == EINTR || errno == EWOULDBLOCK) {
				continue;
			}

			if (nRet == -1)
			{
				int ret = ReConnection();
				if (ret == 1)  continue;
				else return ret;
			}
		}
		else
		{
			int ret = ReConnection();
			if (ret == 1)  continue;
			else return ret;
		}

	}
	return nRet;
}

void LSocket::Close()
{
	closesocket(this->sockfd);
}


int LSocket::ReConnection()
{
	closesocket(this->sockfd);
	std::string err;
	INFO("Send error Try to ReConnecttion...");
	if (TcpConnect(err) != -1)
	{
		INFO("Send error Try to ReConnecttion...Success");
		return 1;
	}
	else
	{
		INFO("Send error Try to ReConnecttion...Error");
		return -1;
	}
}
