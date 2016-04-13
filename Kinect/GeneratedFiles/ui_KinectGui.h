/********************************************************************************
** Form generated from reading UI file 'KinectGui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KINECTGUI_H
#define UI_KINECTGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KinectGuiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KinectGuiClass)
    {
        if (KinectGuiClass->objectName().isEmpty())
            KinectGuiClass->setObjectName(QStringLiteral("KinectGuiClass"));
        KinectGuiClass->resize(600, 400);
        menuBar = new QMenuBar(KinectGuiClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        KinectGuiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KinectGuiClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KinectGuiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(KinectGuiClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        KinectGuiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(KinectGuiClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KinectGuiClass->setStatusBar(statusBar);

        retranslateUi(KinectGuiClass);

        QMetaObject::connectSlotsByName(KinectGuiClass);
    } // setupUi

    void retranslateUi(QMainWindow *KinectGuiClass)
    {
        KinectGuiClass->setWindowTitle(QApplication::translate("KinectGuiClass", "KinectGui", 0));
    } // retranslateUi

};

namespace Ui {
    class KinectGuiClass: public Ui_KinectGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KINECTGUI_H
