#include "registerwidget.h"
#include "style.h"

#pragma execution_character_set("utf-8")

RegisterWidget::RegisterWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
	setFixedSize(this->width(), this->height());
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::WindowTitleHint);

	
	ui.btnClose->raise();
	ui.leUName->setPlaceholderText(("请输入用户名"));
	ui.lePassword->setPlaceholderText("请输入密码");
	ui.lePassword->setEchoMode(QLineEdit::Password);
	ui.lePassword->setMaxLength(16);
	ui.lePassword_2->setPlaceholderText("请输入密码");
	ui.lePassword_2->setEchoMode(QLineEdit::Password);
	ui.lePassword_2->setMaxLength(16);
	ui.lePassword->setStyleSheet(QString::fromStdString(MyStyle::LINEEDITSTYLE));
	ui.lePassword_2->setStyleSheet(QString::fromStdString(MyStyle::LINEEDITSTYLE));
	ui.leUName->setStyleSheet(QString::fromStdString(MyStyle::LINEEDITSTYLE));
}

RegisterWidget::~RegisterWidget()
{
}

//发送信号给其他连接的窗体
void RegisterWidget::SendOverSignal()
{
	emit RegistetOver();
}

void RegisterWidget::CloseRegisterForm()
{
	SendOverSignal();
	this->close();
}

