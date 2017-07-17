#include <SoAppRunner.Desktop/SoCustomWidget.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPalette>

SoCustomWidget::SoCustomWidget(QColor background, QWidget* parent)
    : QWidget(parent), _background(background)
{
	setContentsMargins(0, 0, 0, 0);
	updateBg();
}




SoCustomWidget::~SoCustomWidget()
{

}

void SoCustomWidget::updateBg()
{
	QPalette pal = palette();

	pal.setColor(QPalette::Background, _background);
	setAutoFillBackground(true);
	setPalette(pal);
}

void SoCustomWidget::setBackgroundColor(QColor bg)
{
	_background = bg;
	updateBg();
}


