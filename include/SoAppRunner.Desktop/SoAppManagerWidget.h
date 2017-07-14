// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_APP_MANAGER_WIDGET_H
#define SO_APP_MANAGER_WIDGET_H

#include <SoAppRunner.Desktop/SoCustomWidget.h>

#include <SoAppRunner/SoAppManager.h>
#include <SoAppRunner.Desktop/SoAppRunnerDesktopExport.h>

//
class SO_APPRUNNER_DESKTOP_API SoAppManagerWidget : public SoCustomWidget
{
	Q_OBJECT
public:
	SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr);
	virtual ~SoAppManagerWidget();


private:
	SoAppManager* _appMgr;
};

#endif // SO_APP_MANAGER_WIDGET_H
