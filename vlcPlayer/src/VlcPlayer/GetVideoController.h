#pragma once
#include <qthread.h>
#include "socket.h"
#include <qlist.h>
#include <qmap.h>
class GetVideoController
	: public QThread

{
	Q_OBJECT
public:

	GetVideoController(QObject *parent = 0);

	void run() override;

signals:
	void dealOver(QList<QMap<QString, QString>> res);
public:
	LSocket * lsocket = nullptr;
};

