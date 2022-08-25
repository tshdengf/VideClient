#pragma once

#include <QWidget>
#include "ui_registerwidget.h"

class RegisterWidget : public QWidget
{
	Q_OBJECT

public:
	RegisterWidget(QWidget *parent = Q_NULLPTR);
	~RegisterWidget();

	void SendOverSignal();

public slots:
	void CloseRegisterForm();

	//信号 必须以signal开头
	//无返回值
	//只是函数的声明，不需要定义.
signals:
	void RegistetOver();

private:
	Ui::registerwidget ui;
};
