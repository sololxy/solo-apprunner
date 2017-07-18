// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef MIAN_WINDOW_H
#define MIAN_WINDOW_H

#include <QMainWindow>
#include <SoAppRunner.Desktop/SoAppManagerWidget.h>


class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = NULL);
	~MainWindow();

private:
	SoAppManagerWidget* appMgrWidget;

};

#endif // MIAN_WINDOW_H