#include "KinectGui.h"
#include "KinectProcess.h"


KinectGui::KinectGui(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle("Ozan's Kinect");

	setFixedWidth(800);
	setFixedHeight(600);
}

KinectGui::~KinectGui()
{

}

void KinectGui::paintEvent(QPaintEvent *pe)
{
	QPainter painter(this);
	QPen pen(Qt::black, 2, Qt::SolidLine);

	painter.setPen(pen);
	painter.drawLine(0, 0, 100, 100);
	return;
}