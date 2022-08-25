#include "customslider.h"

#include <qdebug.h>

void CustomSlider::mousePressEvent(QMouseEvent *ev)
{
	//ע��Ӧ�ȵ��ø��������������¼����������Բ�Ӱ���϶������
	QSlider::mousePressEvent(ev);
	//��ȡ����λ�ã����ﲢ����ֱ�Ӵ�ev��ȡֵ����Ϊ������϶��Ļ�����꿪ʼ�����λ��û�������ˣ�
	double pos = ev->pos().x() / (double)width();
	int value = pos * (maximum() - minimum()) + minimum();
	setValue(value);

	qDebug() << value;
	//�����Զ������굥���ź�
	emit costomSliderClicked(value);
}