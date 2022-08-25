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

	//�ź� ������signal��ͷ
	//�޷���ֵ
	//ֻ�Ǻ���������������Ҫ����.
signals:
	void RegistetOver();

private:
	Ui::registerwidget ui;
};
