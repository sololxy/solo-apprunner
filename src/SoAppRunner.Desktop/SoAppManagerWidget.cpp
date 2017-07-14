#include <SoAppRunner.Desktop/SoAppManagerWidget.h>

#include <QVBoxLayout>

SoAppManagerWidget::SoAppManagerWidget(QWidget* parent, SoAppManager* appMgr)
    : QWidget(parent), _appMgr(appMgr)
{
	QVBoxLayout* layout = new QVBoxLayout();

	this->setWindowTitle(_appMgr->name());

	setLayout(layout);
}


SoAppManagerWidget::~SoAppManagerWidget()
{

}
