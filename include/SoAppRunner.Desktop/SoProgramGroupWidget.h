// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_PROGRAM_GROUP_WIDGET_H
#define SO_PROGRAM_GROUP_WIDGET_H

#include <QWidget>

#include <SoAppRunner/SoProgramGroup.h>

#include <SoAppRunner.Desktop/SoAppRunnerDesktopExport.h>

//
class SO_APPRUNNER_DESKTOP_API SoProgramGroupWidget : public QWidget
{
	Q_OBJECT
public:
	SoProgramGroupWidget(QWidget* parent, SoProgramGroup* group);
	virtual ~SoProgramGroupWidget();


private:
	SoProgramGroup* _group;
};

#endif // SO_PROGRAM_GROUP_WIDGET_H
