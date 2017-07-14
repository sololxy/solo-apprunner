#include <SoAppRunner.Desktop/SoProgramWidget.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

SoProgramWidget::SoProgramWidget(QWidget* parent, SoProgram* program)
    : QWidget(parent), _program(program)
{
	setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* layout = new QHBoxLayout();
	layout->setContentsMargins(0, 0, 0, 0);
	
	// ÉèÖÃicon
	QWidget* leftWidget = new QWidget(this);
	leftWidget->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout* layoutLeft = new QVBoxLayout();
	layoutLeft->setContentsMargins(0, 0, 0, 0);
	leftWidget->setLayout(layoutLeft);

	QPushButton* iconWidget = new QPushButton(leftWidget);
	iconWidget->setMinimumSize(120, 120);
	iconWidget->setFixedSize(120, 120);
	layoutLeft->addWidget(iconWidget);
	
	layoutLeft->addStretch();
	layout->addWidget(leftWidget);

	QWidget* rightWidget = new QWidget(this);
	rightWidget->setFixedWidth(300);
	rightWidget->setContentsMargins(0, 0, 0, 0);
	QVBoxLayout* layoutRight = new QVBoxLayout();
	layoutRight->setContentsMargins(0, 0, 0, 0);
	rightWidget->setLayout(layoutRight);
	
	QLabel* nameLabel = new QLabel(rightWidget);
	nameLabel->setText(program->name());
	layoutRight->addWidget(nameLabel);

	QLabel* pathLabel = new QLabel(rightWidget);
	pathLabel->setText(program->path());
	layoutRight->addWidget(pathLabel);


	//layoutRight->addStretch();
	layout->addWidget(rightWidget);

	//layout->addStretch();
	setLayout(layout);
}


SoProgramWidget::~SoProgramWidget()
{

}
