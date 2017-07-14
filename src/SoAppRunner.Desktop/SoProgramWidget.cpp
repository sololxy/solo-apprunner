#include <SoAppRunner.Desktop/SoProgramWidget.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SoProgramWidget::SoProgramWidget(QWidget* parent, SoProgram* program)
    : QWidget(parent), _program(program)
{
	QHBoxLayout* layout = new QHBoxLayout();
	
	// ÉèÖÃicon
	QWidget* leftWidget = new QWidget(this);
	QVBoxLayout* layoutLeft = new QVBoxLayout();
	leftWidget->setLayout(layoutLeft);

	QPushButton* iconWidget = new QPushButton(leftWidget);
	iconWidget->setMinimumSize(120, 120);
	layoutLeft->addWidget(iconWidget);
	
	layoutLeft->addStretch();
	layout->addWidget(leftWidget);

	QWidget* rightWidget = new QWidget(this);
	QVBoxLayout* layoutRight = new QVBoxLayout();
	rightWidget->setLayout(layoutRight);
	
	QLabel* nameLabel = new QLabel(rightWidget);
	nameLabel->setText(program->name());
	layoutRight->addWidget(nameLabel);

	QLabel* pathLabel = new QLabel(rightWidget);
	pathLabel->setText(program->path());
	layoutRight->addWidget(pathLabel);


	layoutRight->addStretch();
	layout->addWidget(rightWidget);

	setLayout(layout);
}


SoProgramWidget::~SoProgramWidget()
{

}
