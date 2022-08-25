/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <customslider.h>

QT_BEGIN_NAMESPACE

class Ui_mainwidget
{
public:
    QLabel *lblTtitle;
    QPushButton *pushButton;
    QFrame *frmPlay;
    QPushButton *btnUserInfo;
    QListView *lstvPlayList;
    CustomSlider *tbPlayTack;
    QPushButton *btnRate;
    QLabel *lbPlayTime;
    QLabel *lbTotalTime;
    QLabel *lbl2;
    QPushButton *pushButton_2;
    QPushButton *btnStop;
    QPushButton *btnCut;
    QProgressBar *prbFileUp;

    void setupUi(QWidget *mainwidget)
    {
        if (mainwidget->objectName().isEmpty())
            mainwidget->setObjectName(QStringLiteral("mainwidget"));
        mainwidget->resize(1080, 720);
        mainwidget->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"border-radius: 15px"));
        lblTtitle = new QLabel(mainwidget);
        lblTtitle->setObjectName(QStringLiteral("lblTtitle"));
        lblTtitle->setGeometry(QRect(50, 0, 1001, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        lblTtitle->setFont(font);
        lblTtitle->setLayoutDirection(Qt::LeftToRight);
        lblTtitle->setStyleSheet(QStringLiteral("color: rgb(170, 255, 255);"));
        lblTtitle->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(mainwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1060, 0, 21, 23));
        QFont font1;
        font1.setFamily(QStringLiteral("Constantia"));
        font1.setPointSize(8);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(18, 218, 218);"));
        frmPlay = new QFrame(mainwidget);
        frmPlay->setObjectName(QStringLiteral("frmPlay"));
        frmPlay->setGeometry(QRect(80, 50, 1001, 631));
        QFont font2;
        font2.setPointSize(11);
        frmPlay->setFont(font2);
        frmPlay->setFrameShape(QFrame::StyledPanel);
        frmPlay->setFrameShadow(QFrame::Raised);
        btnUserInfo = new QPushButton(mainwidget);
        btnUserInfo->setObjectName(QStringLiteral("btnUserInfo"));
        btnUserInfo->setGeometry(QRect(0, 0, 32, 32));
        btnUserInfo->setStyleSheet(QString::fromUtf8("background-image: url(:/VlcPlayer/D:/\350\213\217\345\265\214\345\220\210\344\275\234/\345\233\276\347\211\207/\344\270\252\344\272\272\344\277\241\346\201\257.png);"));
        lstvPlayList = new QListView(mainwidget);
        lstvPlayList->setObjectName(QStringLiteral("lstvPlayList"));
        lstvPlayList->setGeometry(QRect(0, 51, 81, 661));
        lstvPlayList->setStyleSheet(QStringLiteral("background-color: rgb(147, 147, 147)"));
        tbPlayTack = new CustomSlider(mainwidget);
        tbPlayTack->setObjectName(QStringLiteral("tbPlayTack"));
        tbPlayTack->setGeometry(QRect(90, 690, 811, 22));
        tbPlayTack->setMinimum(1);
        tbPlayTack->setMaximum(100);
        tbPlayTack->setOrientation(Qt::Horizontal);
        btnRate = new QPushButton(mainwidget);
        btnRate->setObjectName(QStringLiteral("btnRate"));
        btnRate->setGeometry(QRect(900, 688, 41, 23));
        btnRate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbPlayTime = new QLabel(mainwidget);
        lbPlayTime->setObjectName(QStringLiteral("lbPlayTime"));
        lbPlayTime->setGeometry(QRect(938, 690, 61, 21));
        lbPlayTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbTotalTime = new QLabel(mainwidget);
        lbTotalTime->setObjectName(QStringLiteral("lbTotalTime"));
        lbTotalTime->setGeometry(QRect(1018, 690, 61, 21));
        lbTotalTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl2 = new QLabel(mainwidget);
        lbl2->setObjectName(QStringLiteral("lbl2"));
        lbl2->setGeometry(QRect(1000, 690, 16, 21));
        lbl2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lbl2->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(mainwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 10, 51, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(85, 255, 255);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btnStop = new QPushButton(mainwidget);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setGeometry(QRect(350, 10, 41, 23));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        btnStop->setFont(font3);
        btnStop->setStyleSheet(QStringLiteral("color: rgb(170, 255, 255);"));
        btnCut = new QPushButton(mainwidget);
        btnCut->setObjectName(QStringLiteral("btnCut"));
        btnCut->setEnabled(false);
        btnCut->setGeometry(QRect(390, 10, 41, 23));
        btnCut->setFont(font3);
        btnCut->setStyleSheet(QStringLiteral("color: rgb(170, 255, 255);"));
        prbFileUp = new QProgressBar(mainwidget);
        prbFileUp->setObjectName(QStringLiteral("prbFileUp"));
        prbFileUp->setGeometry(QRect(170, 10, 171, 23));
        prbFileUp->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        prbFileUp->setValue(0);

        retranslateUi(mainwidget);
        QObject::connect(pushButton, SIGNAL(clicked()), mainwidget, SLOT(Close()));
        QObject::connect(btnRate, SIGNAL(clicked()), mainwidget, SLOT(RateClick()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mainwidget, SLOT(UPFileClick()));
        QObject::connect(btnCut, SIGNAL(clicked()), mainwidget, SLOT(CutUpLoad()));

        QMetaObject::connectSlotsByName(mainwidget);
    } // setupUi

    void retranslateUi(QWidget *mainwidget)
    {
        mainwidget->setWindowTitle(QApplication::translate("mainwidget", "\350\213\217\345\265\214\347\275\221\350\257\276\345\271\263\345\217\260", Q_NULLPTR));
        lblTtitle->setText(QApplication::translate("mainwidget", "\350\213\217\345\265\214\347\275\221\350\257\276\345\271\263\345\217\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("mainwidget", "X", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnUserInfo->setToolTip(QApplication::translate("mainwidget", "\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnUserInfo->setText(QString());
#ifndef QT_NO_TOOLTIP
        lstvPlayList->setToolTip(QApplication::translate("mainwidget", "\346\222\255\346\224\276\345\210\227\350\241\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRate->setText(QApplication::translate("mainwidget", "1", Q_NULLPTR));
        lbPlayTime->setText(QApplication::translate("mainwidget", "0:0:0", Q_NULLPTR));
        lbTotalTime->setText(QApplication::translate("mainwidget", "0:0:0", Q_NULLPTR));
        lbl2->setText(QApplication::translate("mainwidget", ":", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mainwidget", "\344\270\212\344\274\240\350\247\206\351\242\221", Q_NULLPTR));
        btnStop->setText(QApplication::translate("mainwidget", "\346\232\202\345\201\234", Q_NULLPTR));
        btnCut->setText(QApplication::translate("mainwidget", "\345\201\234\346\255\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainwidget: public Ui_mainwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
