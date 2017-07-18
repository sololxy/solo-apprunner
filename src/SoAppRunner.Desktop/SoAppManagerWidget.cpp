#include <SoAppRunner.Desktop/SoAppManagerWidget.h>
#include <SoAppRunner.Desktop/SoProgramGroupWidget.h>

#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>

SoAppManagerWidget::SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr)
	: QScrollArea(parent), _appMgr(appMgr)
{
	setWindowTitle(_appMgr->name());

	QWidget* mainWindow = new QWidget(this);

	QVBoxLayout* layout = new QVBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* layoutGroup = new QVBoxLayout();
	layoutGroup->setContentsMargins(0,0,0,0);
	for (int i = 0; i < _appMgr->groups().size(); i++) {
		SoProgramGroup* group = _appMgr->groups()[i];

		if (NULL == group) continue;

		SoProgramGroupWidget* groupWidget = new SoProgramGroupWidget(NULL, group);
		layoutGroup->addWidget(groupWidget);
	}

	layout->addLayout(layoutGroup);


	QSpacerItem* spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum,
		QSizePolicy::Expanding);
	layout->addItem(spacer);

	mainWindow->setLayout(layout);

	this->setWidget(mainWindow);
	this->setWidgetResizable(true);
}


SoAppManagerWidget::~SoAppManagerWidget()
{

}
