#include <SoAppRunner.Desktop/SoProgramGroupWidget.h>
#include <SoAppRunner.Desktop/SoProgramWidget.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

SoProgramGroupWidget::SoProgramGroupWidget(QWidget* parent, SoProgramGroup* group)
    : QWidget(parent), _group(group)
{

	if (NULL != _group) {

		QVBoxLayout* layoutMain = new QVBoxLayout();
		QLabel* labelGroup = new QLabel(QString("<b><font size=16 color='green'>%1</font></b>").arg(_group->name()));
		layoutMain->addWidget(labelGroup);

		QWidget* widgetMain = new QWidget(this);
		layoutMain->addWidget(widgetMain);

		QHBoxLayout* layout = new QHBoxLayout();
		widgetMain->setLayout(layout);

		for (int i = 0; i < _group->programs().size(); i++) {
			SoProgram* program = _group->programs()[i];

			if(NULL == program) continue;

			SoProgramWidget* programWidget = new SoProgramWidget(widgetMain, program);
			layout->addWidget(programWidget);
		}

		setLayout(layoutMain);
	}

	
}


SoProgramGroupWidget::~SoProgramGroupWidget()
{
	
}
