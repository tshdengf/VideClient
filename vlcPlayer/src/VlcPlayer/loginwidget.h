#pragma once

#include <QWidget>
#include <QmouseEvent>
#include "socket.h"
#include "ui_loginwidget.h"
#include "registerwidget.h"
#include "mainwidget.h"

class LoginWidget : public QWidget
{
	Q_OBJECT

public:

    void SendHeart();

	LoginWidget(QWidget *parent = Q_NULLPTR);
	~LoginWidget();

public slots:
	void CloseForm();
	void ShowRegisterForm();
	void ClientLogin();

	void ShowLoginForm();

protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);

	void keyPressEvent(QKeyEvent *event) override;

private:
	Ui::loginWidget ui;
private:
	QPoint last;
	void InitLoginWidget();
	RegisterWidget registerForm;

	MainWidget * mainForm = nullptr;

	LSocket * conn = nullptr;
};
