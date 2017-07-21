#include "MainWindow.h"
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "BannerWidget.h"

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent)
{
        QVBoxLayout* layout = new QVBoxLayout();
	QWidget* centralWidget = new QWidget();
	centralWidget->setContentsMargins(0, 0, 0, 0);

	BannerWidget* banner = new BannerWidget(centralWidget);
	banner->setFixedHeight(100);
	layout->addWidget(banner);
	
	layout->setContentsMargins(0,0,0,0);

	appMgrWidget = new SoAppManagerWidget(centralWidget, SoAppManager::instance());
        layout->addWidget(appMgrWidget);

	centralWidget->setLayout(layout);
	setCentralWidget(centralWidget);

        // 更改layout中的间隙，fixed #1
        layout->setSpacing(0);
        
}

MainWindow::~MainWindow()
{

}
