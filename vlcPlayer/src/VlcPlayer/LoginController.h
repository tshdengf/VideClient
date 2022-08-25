#pragma once
#include <qstring.h>
#include <iostream>
#include "socket.h"
//µÇÂ¼¿ØÖÆÆ÷
class LoginController
{

public:
	static bool LoginController::Login(QString uName, QString password, QString &error, LSocket** serverConn);

};

