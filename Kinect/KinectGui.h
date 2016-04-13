#ifndef KINECTGUI_H
#define KINECTGUI_H

#include <QtWidgets/QMainWindow>
#include <QtGui\qpainter.h>

class KinectGui : public QMainWindow
{
	Q_OBJECT

public:
	KinectGui(QWidget *parent = 0);
	~KinectGui();

	void paintEvent(QPaintEvent *pe);

private:

};

#endif // KINECTGUI_H
