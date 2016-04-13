#ifndef KINECTGUI_H
#define KINECTGUI_H

#include <QtWidgets/QMainWindow>
#include "ui_KinectGui.h"

class KinectGui : public QMainWindow
{
	Q_OBJECT

public:
	KinectGui(QWidget *parent = 0);
	~KinectGui();

private:
	Ui::KinectGuiClass ui;
};

#endif // KINECTGUI_H
