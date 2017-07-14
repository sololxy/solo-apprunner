#include <SoAppRunner.Desktop/SoAppManagerWidget.h>
#include <SoAppRunner.Desktop/SoProgramGroupWidget.h>

#include <QVBoxLayout>
#include <QLabel>

SoAppManagerWidget::SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr)
	: QWidget(parent), _appMgr(appMgr)
{
	QVBoxLayout* layout = new QVBoxLayout();

	this->setWindowTitle(_appMgr->name());

	
	for (int i = 0; i < _appMgr->groups().size(); i++) {
		SoProgramGroup* group = _appMgr->groups()[i];

		if (NULL == group) continue;

		SoProgramGroupWidget* groupWidget = new SoProgramGroupWidget(NULL, group);
		layout->addWidget(groupWidget);
	}

	layout->addStretch();
	setLayout(layout);

}


SoAppManagerWidget::~SoAppManagerWidget()
{

}
