#include "BannerWidget.h"
#include <QHBoxLayout>
#include <QLabel>

#include <SoAppRunner/SoAppManager.h>

BannerWidget::BannerWidget(QWidget* parent): SoCustomWidget(QColor(255, 255, 255, 255), parent)
{
	setFixedHeight(100);

	QHBoxLayout* layout = new QHBoxLayout();

	QString title = QString("<font size=12 color='green'>%1</font>")
		.arg(SoAppManager::instance()->name());
	QLabel* titleLabel = new QLabel(title);
	titleLabel->setAlignment(Qt::AlignCenter);
	layout->addWidget(titleLabel);
	
	layout->setContentsMargins(0, 0, 0, 0);
	setLayout(layout);
}

BannerWidget::~BannerWidget()
{

}
