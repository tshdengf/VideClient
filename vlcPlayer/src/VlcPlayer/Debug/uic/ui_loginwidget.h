/********************************************************************************
** Form generated from reading UI file 'loginwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIDGET_H
#define UI_LOGINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QFrame *frame;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *tlbUName;
    QLabel *tlbPassword;
    QLineEdit *lePassword;
    QLineEdit *leUName;
    QPushButton *btnLogin;
    QLabel *lblWelcome;
    QPushButton *pushButton;
    QPushButton *btnRegiste;
    QPushButton *btnRegiste_2;
    QFrame *frame_2;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->resize(500, 336);
        loginWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px"));
        frame = new QFrame(loginWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(190, 0, 311, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 70, 281, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        tlbUName = new QLabel(formLayoutWidget);
        tlbUName->setObjectName(QStringLiteral("tlbUName"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(15);
        tlbUName->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, tlbUName);

        tlbPassword = new QLabel(formLayoutWidget);
        tlbPassword->setObjectName(QStringLiteral("tlbPassword"));
        tlbPassword->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, tlbPassword);

        lePassword = new QLineEdit(formLayoutWidget);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lePassword->setFont(font1);

        formLayout->setWidget(4, QFormLayout::FieldRole, lePassword);

        leUName = new QLineEdit(formLayoutWidget);
        leUName->setObjectName(QStringLiteral("leUName"));
        leUName->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, leUName);

        btnLogin = new QPushButton(frame);
        btnLogin->setObjectName(QStringLiteral("btnLogin"));
        btnLogin->setGeometry(QRect(50, 250, 201, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        btnLogin->setFont(font2);
        btnLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-radius: 8px;"));
        lblWelcome = new QLabel(frame);
        lblWelcome->setObjectName(QStringLiteral("lblWelcome"));
        lblWelcome->setGeometry(QRect(-30, 0, 371, 61));
        lblWelcome->setStyleSheet(QString::fromUtf8("background-image: url(:/VlcPlayer/D:/\350\213\217\345\265\214\345\220\210\344\275\234/\345\233\276\347\211\207/\346\254\242\350\277\216.jpg);"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 0, 21, 23));
        QFont font3;
        font3.setFamily(QStringLiteral("Constantia"));
        font3.setPointSize(8);
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(218, 218, 218);"));
        btnRegiste = new QPushButton(frame);
        btnRegiste->setObjectName(QStringLiteral("btnRegiste"));
        btnRegiste->setGeometry(QRect(0, 210, 61, 20));
        btnRegiste->setFont(font1);
        btnRegiste_2 = new QPushButton(frame);
        btnRegiste_2->setObjectName(QStringLiteral("btnRegiste_2"));
        btnRegiste_2->setGeometry(QRect(230, 210, 61, 20));
        btnRegiste_2->setFont(font1);
        frame_2 = new QFrame(loginWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, -10, 191, 351));
        frame_2->setStyleSheet(QString::fromUtf8("background-image: url(:/VlcPlayer/D:/\350\213\217\345\265\214\345\220\210\344\275\234/\350\247\206\351\242\221\344\274\240\350\276\223/\345\233\276\347\211\207/\350\203\214\346\231\2572.jpg);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        retranslateUi(loginWidget);
        QObject::connect(pushButton, SIGNAL(clicked()), loginWidget, SLOT(CloseForm()));
        QObject::connect(btnRegiste, SIGNAL(clicked()), loginWidget, SLOT(ShowRegisterForm()));
        QObject::connect(btnLogin, SIGNAL(clicked()), loginWidget, SLOT(ClientLogin()));

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QApplication::translate("loginWidget", "loginWidget", Q_NULLPTR));
        tlbUName->setText(QApplication::translate("loginWidget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        tlbPassword->setText(QApplication::translate("loginWidget", "\345\257\206\347\240\201", Q_NULLPTR));
        lePassword->setText(QString());
        leUName->setText(QString());
        btnLogin->setText(QApplication::translate("loginWidget", "\347\231\273\345\275\225", Q_NULLPTR));
        lblWelcome->setText(QString());
        pushButton->setText(QApplication::translate("loginWidget", "X", Q_NULLPTR));
        btnRegiste->setText(QApplication::translate("loginWidget", "\346\263\250\345\206\214", Q_NULLPTR));
        btnRegiste_2->setText(QApplication::translate("loginWidget", "\345\277\230\350\256\260\345\257\206\347\240\201?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIDGET_H
