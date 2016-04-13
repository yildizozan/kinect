#include "KinectGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KinectGui w;
	w.show();
	return a.exec();
}
