#include "loginwidget.h"
#include "style.h"
#include "settingutil.h"
#include "socket.h"
#include "MsgDefine.h"
#include <string.h>
#include <QDebug>
#include <thread>
#include "registerwidget.h"
#include "LoginController.h"
#include <qmessagebox.h>

//解决中文乱码
#pragma execution_character_set("utf-8")


LoginWidget::LoginWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	InitLoginWidget();
	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
	setFixedSize(this->width(), this->height());
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowTitleHint);
}

LoginWidget::~LoginWidget()
{
}

/*
初始化整体界面控件
*/
void LoginWidget::InitLoginWidget()
{
	ui.leUName->setPlaceholderText(("请输入手机号"));
	ui.lePassword->setPlaceholderText("请输入密码");
	ui.lePassword->setEchoMode(QLineEdit::Password);
	ui.lePassword->setMaxLength(16);
	ui.lePassword->setStyleSheet(QString::fromStdString(MyStyle::LINEEDITSTYLE));
	ui.leUName->setStyleSheet(QString::fromStdString(MyStyle::LINEEDITSTYLE));

	//初始化配置
	Setting::Init();

	//处理信号, 信号是谁发出的， 发出什么信号， 谁来接 用什么处理
	connect(&registerForm, &RegisterWidget::RegistetOver, this, &LoginWidget::ShowLoginForm);
}


void LoginWidget::CloseForm()
{
	this->close();
}

//注册事件发生
void LoginWidget::ShowRegisterForm()
{
	registerForm.show();
	this->hide();
}

//登录事件发生
void LoginWidget::ClientLogin()
{
	QString loginMsg;
	bool success =  LoginController::Login(ui.leUName->text(), ui.tlbPassword->text(), loginMsg, &conn);
	if (!success)
	{
		QMessageBox::warning(this, "Login Msg", "Login Error" + loginMsg, QMessageBox::StandardButton::Ok);
	}
	else
	{
		//登录成功
		this->mainForm = new MainWidget();
		this->mainForm->Init(conn);
		this->close();
		this->mainForm->show();
	}


}

void LoginWidget::ShowLoginForm()
{
	this->show();
}


//解决窗体不能拖动的问题
void LoginWidget::mousePressEvent(QMouseEvent *e)
{
	last = e->globalPos();
}
void LoginWidget::mouseMoveEvent(QMouseEvent *e) 
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	last = e->globalPos();
	move(x() + dx, y() + dy);
}
void LoginWidget::mouseReleaseEvent(QMouseEvent *e) 
{
	int dx = e->globalX() - last.x();
	int dy = e->globalY() - last.y();
	move(x() + dx, y() + dy);
}
void LoginWidget::keyPressEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key::Key_Enter)
	{
		this->ClientLogin();
	}

}
//发送心跳包
void LoginWidget::SendHeart()
{
	int coun = 0;
	while (1)
	{
		MsgHeader head(0, HEART_CHECK);
		char buffer[MSG_HEAD_LEN] = "\0";
		memcpy(buffer, &head, MSG_HEAD_LEN);
		conn->Send((const char *)buffer, MSG_HEAD_LEN);
		Sleep(60000);
	}
}

