#include <SoAppRunner.Desktop/SoAppManagerWidget.h>
#include <SoAppRunner.Desktop/SoProgramGroupWidget.h>

#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>

SoAppManagerWidget::SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr)
	: SoCustomWidget(QColor(0x00, 0x00, 0x00),parent), _appMgr(appMgr)
{
	setWindowTitle(_appMgr->name());

	QVBoxLayout* layout = new QVBoxLayout();

	SoCustomWidget* banner = new SoCustomWidget(QColor(255, 255, 255, 255));
	banner->setFixedHeight(200);
	layout->addWidget(banner);

	layout->setContentsMargins(0, 0, 0, 0);
	
	for (int i = 0; i < _appMgr->groups().size(); i++) {
		SoProgramGroup* group = _appMgr->groups()[i];

		if (NULL == group) continue;

		SoProgramGroupWidget* groupWidget = new SoProgramGroupWidget(NULL, group);
		layout->addWidget(groupWidget);
	}

	QSpacerItem* spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, 
										  QSizePolicy::Expanding);
	layout->addItem(spacer);
	setLayout(layout);

}


SoAppManagerWidget::~SoAppManagerWidget()
{

}
