#include <QCoreApplication>
#include <QApplication>

#include "MainWindow.h"

int main(int argn, char** argv)
{
    QApplication app(argn,argv);

    QString configPath = QCoreApplication::applicationDirPath() 
                         + "/config/app.config";

    QString appName = "Test AppRunner";
    if (true == SoAppManager::instance()->open(configPath))
        appName = SoAppManager::instance()->name();


	MainWindow mw;
	
	mw.setWindowTitle(appName);
	mw.showMaximized();

    return app.exec();
}
