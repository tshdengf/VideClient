#pragma once

#include <Windows.h>
#include <iostream>
class LSocket
{

public:
	~LSocket();
	int TcpConnect(std::string & error);
	int Send(const char *, int);
	int Recv(char *, int);

	void Close();

	int ReConnection();

public:
	int sockfd;

};

