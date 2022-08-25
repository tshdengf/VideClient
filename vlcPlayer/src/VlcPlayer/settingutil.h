#pragma once

//QT…Ë÷√¿‡
#include <QString>
#include <QSettings>
#include <QDir>
#include <qobject.h>
#include <qcoreapplication.h>
#include <Windows.h>

#pragma execution_character_set("utf-8")

class Setting
{
public:
	static  QString SERVER_ADDRESS;
	static  qint32 SERVER_PORT;
public:
	static void Init(QString settingFilename = "");
};


