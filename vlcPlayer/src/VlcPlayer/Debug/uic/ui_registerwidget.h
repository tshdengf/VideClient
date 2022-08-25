/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

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

class Ui_registerwidget
{
public:
    QFrame *frmBack;
    QFrame *frame;
    QPushButton *btnClose;
    QLabel *lblWelcome;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *tlbUName;
    QLabel *tlbPassword;
    QLineEdit *lePassword;
    QLineEdit *leUName;
    QLabel *tlbPassword_2;
    QLineEdit *lePassword_2;
    QPushButton *btnRegiste;

    void setupUi(QWidget *registerwidget)
    {
        if (registerwidget->objectName().isEmpty())
            registerwidget->setObjectName(QStringLiteral("registerwidget"));
        registerwidget->resize(500, 336);
        registerwidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius: 15px"));
        frmBack = new QFrame(registerwidget);
        frmBack->setObjectName(QStringLiteral("frmBack"));
        frmBack->setGeometry(QRect(0, -10, 191, 351));
        frmBack->setStyleSheet(QString::fromUtf8("background-image: url(:/VlcPlayer/D:/\350\213\217\345\265\214\345\220\210\344\275\234/\350\247\206\351\242\221\344\274\240\350\276\223/\345\233\276\347\211\207/\350\203\214\346\231\2572.jpg);"));
        frmBack->setFrameShape(QFrame::StyledPanel);
        frmBack->setFrameShadow(QFrame::Raised);
        frame = new QFrame(registerwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(190, 0, 311, 341));
        frame->setAutoFillBackground(false);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        btnClose = new QPushButton(frame);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(290, 0, 21, 23));
        QFont font;
        font.setFamily(QStringLiteral("Constantia"));
        font.setPointSize(8);
        btnClose->setFont(font);
        btnClose->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(218, 218, 218);"));
        lblWelcome = new QLabel(frame);
        lblWelcome->setObjectName(QStringLiteral("lblWelcome"));
        lblWelcome->setGeometry(QRect(-30, 0, 371, 61));
        lblWelcome->setStyleSheet(QString::fromUtf8("background-image: url(:/VlcPlayer/D:/\350\213\217\345\265\214\345\220\210\344\275\234/\345\233\276\347\211\207/\346\263\250\345\206\214.jpg);"));
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 281, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(8);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        tlbUName = new QLabel(formLayoutWidget);
        tlbUName->setObjectName(QStringLiteral("tlbUName"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(15);
        tlbUName->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, tlbUName);

        tlbPassword = new QLabel(formLayoutWidget);
        tlbPassword->setObjectName(QStringLiteral("tlbPassword"));
        tlbPassword->setFont(font1);

        formLayout->setWidget(3, QFormLayout::FieldRole, tlbPassword);

        lePassword = new QLineEdit(formLayoutWidget);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        lePassword->setFont(font2);

        formLayout->setWidget(4, QFormLayout::FieldRole, lePassword);

        leUName = new QLineEdit(formLayoutWidget);
        leUName->setObjectName(QStringLiteral("leUName"));
        leUName->setFont(font2);

        formLayout->setWidget(1, QFormLayout::FieldRole, leUName);

        tlbPassword_2 = new QLabel(formLayoutWidget);
        tlbPassword_2->setObjectName(QStringLiteral("tlbPassword_2"));
        tlbPassword_2->setFont(font1);

        formLayout->setWidget(5, QFormLayout::FieldRole, tlbPassword_2);

        lePassword_2 = new QLineEdit(formLayoutWidget);
        lePassword_2->setObjectName(QStringLiteral("lePassword_2"));
        lePassword_2->setFont(font2);

        formLayout->setWidget(6, QFormLayout::FieldRole, lePassword_2);

        btnRegiste = new QPushButton(frame);
        btnRegiste->setObjectName(QStringLiteral("btnRegiste"));
        btnRegiste->setGeometry(QRect(50, 280, 201, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        btnRegiste->setFont(font3);
        btnRegiste->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-radius: 8px;"));

        retranslateUi(registerwidget);
        QObject::connect(btnClose, SIGNAL(clicked()), registerwidget, SLOT(CloseRegisterForm()));
        QObject::connect(btnRegiste, SIGNAL(clicked()), registerwidget, SLOT(Regist()));

        QMetaObject::connectSlotsByName(registerwidget);
    } // setupUi

    void retranslateUi(QWidget *registerwidget)
    {
        registerwidget->setWindowTitle(QApplication::translate("registerwidget", "registerwidget", Q_NULLPTR));
        btnClose->setText(QApplication::translate("registerwidget", "X", Q_NULLPTR));
        lblWelcome->setText(QString());
        tlbUName->setText(QApplication::translate("registerwidget", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        tlbPassword->setText(QApplication::translate("registerwidget", "\345\257\206\347\240\201", Q_NULLPTR));
        lePassword->setText(QString());
        leUName->setText(QString());
        tlbPassword_2->setText(QApplication::translate("registerwidget", "\345\257\206\347\240\201\347\241\256\350\256\244", Q_NULLPTR));
        lePassword_2->setText(QString());
        btnRegiste->setText(QApplication::translate("registerwidget", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerwidget: public Ui_registerwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
