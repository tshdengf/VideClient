#include "loginwidget.h"
#include <QtWidgets/QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	
	LoginWidget w;
	w.show();
	
    return a.exec();
	return 0;
}
