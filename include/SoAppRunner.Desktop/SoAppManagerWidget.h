// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_APP_MANAGER_WIDGET_H
#define SO_APP_MANAGER_WIDGET_H

#include <QScrollArea>
#include <QFrame>

#include <SoAppRunner.Desktop/SoCustomWidget.h>

#include <SoAppRunner/SoAppManager.h>
#include <SoAppRunner.Desktop/SoAppRunnerDesktopExport.h>

//
class SO_APPRUNNER_DESKTOP_API SoAppManagerWidget : public QScrollArea
{
	Q_OBJECT
public:
	SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr);
	virtual ~SoAppManagerWidget();


private:
	SoAppManager* _appMgr;
	QScrollArea* _scrollArea;
};

#endif // SO_APP_MANAGER_WIDGET_H
