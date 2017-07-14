// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_PROGRAM_WIDGET_H
#define SO_PROGRAM_WIDGET_H

#include <QWidget>

#include <SoAppRunner/SoProgram.h>
#include <SoAppRunner.Desktop/SoAppRunnerDesktopExport.h>

//
class SO_APPRUNNER_DESKTOP_API SoProgramWidget : public QWidget
{
    Q_OBJECT
public:
	SoProgramWidget(QWidget* parent, SoProgram* program);
    virtual ~SoProgramWidget();


protected slots:
	void openProgram();

private:
    SoProgram* _program;
};

#endif // SO_PROGRAM_WIDGET_H
