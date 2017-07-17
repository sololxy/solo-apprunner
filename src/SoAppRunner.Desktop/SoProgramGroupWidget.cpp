#include <SoAppRunner.Desktop/SoProgramGroupWidget.h>
#include <SoAppRunner.Desktop/SoProgramWidget.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>

SoProgramGroupWidget::SoProgramGroupWidget(QWidget* parent, SoProgramGroup* group)
    : SoCustomWidget(QColor(0xDD, 0xDD, 0xDD),parent), _group(group)
{

	setContentsMargins(0, 0, 0, 0);

	if (NULL != _group) {

		QVBoxLayout* layoutMain = new QVBoxLayout();
		layoutMain->setContentsMargins(0, 10, 0, 10);

		QString labelGroupText = QString("<b><font size=14 color='green'>%1</font></b>")
									.arg(_group->name());
		QLabel* labelGroup = new QLabel(labelGroupText);
		layoutMain->addWidget(labelGroup);

		QWidget* widgetMain = new QWidget(this);
		widgetMain->setContentsMargins(0, 0, 0, 0);
		layoutMain->addWidget(widgetMain);

		QHBoxLayout* layout = new QHBoxLayout();
		layout->setContentsMargins(0, 0, 0, 0);
		widgetMain->setLayout(layout);

		for (int i = 0; i < _group->programs().size(); i++) {
			SoProgram* program = _group->programs()[i];

			if(NULL == program) continue;

			SoProgramWidget* programWidget = new SoProgramWidget(widgetMain, 
																program);

			programWidget->setFixedHeight(160);
			layout->addWidget(programWidget);
		}

		

		//QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, 
		//									  QSizePolicy::Minimum);
		//layout->addItem(spacer);
		
		setLayout(layoutMain);
	}

	
}


SoProgramGroupWidget::~SoProgramGroupWidget()
{
	
}
