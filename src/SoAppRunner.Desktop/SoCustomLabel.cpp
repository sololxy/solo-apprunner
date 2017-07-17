#include <SoAppRunner.Desktop/SoCustomLabel.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPalette>

SoCustomLabel::SoCustomLabel(QString text,QWidget* parent)
    :  QLabel(text,parent)
{
	_originalText = this->text();
}


SoCustomLabel::~SoCustomLabel()
{

}

void SoCustomLabel::setText(QString text)
{
	QString LINKS_STYLE = "<style>a{color:green;text-decoration: underline;}</style>";

	_originalText = text;

	QLabel::setText(LINKS_STYLE + text);
	
}
