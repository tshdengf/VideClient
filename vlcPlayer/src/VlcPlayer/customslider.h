#pragma once
#include <QSlider>
#include <QMouseEvent>
#include <QCoreApplication>

class CustomSlider : public QSlider
{
	Q_OBJECT
public:
	CustomSlider(QWidget *parent = 0) : QSlider(parent)
	{
	}
protected:
	void mousePressEvent(QMouseEvent *ev);//��дQSlider��mousePressEvent�¼�
signals:
	void costomSliderClicked(int);//�Զ������굥���źţ����ڲ��񲢴���

};
