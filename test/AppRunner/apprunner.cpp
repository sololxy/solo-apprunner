#include <QCoreApplication>
#include <QApplication>
#include <QWidget>

#include <SoAppRunner/SoAppManager.h>
#include <SoAppRunner.Desktop/SoAppManagerWidget.h>

int main(int argn, char** argv)
{
    QApplication app(argn,argv);

	QString configPath = QCoreApplication::applicationDirPath() 
						 + "/config/app.config";

	QString appName = "Test AppRunner";
	if (true == SoAppManager::instance()->open(configPath))
		appName = SoAppManager::instance()->name();

	SoAppManagerWidget widget(NULL, SoAppManager::instance());
	widget.setWindowTitle(appName);
	widget.showMaximized();

    return app.exec();
}
