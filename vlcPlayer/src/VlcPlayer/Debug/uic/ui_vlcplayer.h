/********************************************************************************
** Form generated from reading UI file 'vlcplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VLCPLAYER_H
#define UI_VLCPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VlcPlayerClass
{
public:
    QFrame *videoFrame;

    void setupUi(QWidget *VlcPlayerClass)
    {
        if (VlcPlayerClass->objectName().isEmpty())
            VlcPlayerClass->setObjectName(QStringLiteral("VlcPlayerClass"));
        VlcPlayerClass->resize(600, 400);
        videoFrame = new QFrame(VlcPlayerClass);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setGeometry(QRect(30, 20, 551, 371));
        videoFrame->setFrameShape(QFrame::StyledPanel);
        videoFrame->setFrameShadow(QFrame::Raised);

        retranslateUi(VlcPlayerClass);

        QMetaObject::connectSlotsByName(VlcPlayerClass);
    } // setupUi

    void retranslateUi(QWidget *VlcPlayerClass)
    {
        VlcPlayerClass->setWindowTitle(QApplication::translate("VlcPlayerClass", "VlcPlayer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VlcPlayerClass: public Ui_VlcPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VLCPLAYER_H
