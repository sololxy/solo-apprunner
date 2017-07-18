#include "MainWindow.h"
#include <QVBoxLayout>
#include <QVBoxLayout>

#include "BannerWidget.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)
{
	QWidget* centralWidget = new QWidget(this);
	centralWidget->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* layout = new QVBoxLayout();

	BannerWidget* banner = new BannerWidget(centralWidget);
	banner->setFixedHeight(100);
	layout->addWidget(banner);
	
	layout->setContentsMargins(0, 0, 0, 0);

	appMgrWidget = new SoAppManagerWidget(centralWidget, SoAppManager::instance());
	layout->addWidget(appMgrWidget);

	centralWidget->setLayout(layout);

	setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{

}
