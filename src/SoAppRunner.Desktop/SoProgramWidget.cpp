#include <SoAppRunner.Desktop/SoProgramWidget.h>
#include <SoAppRunner/SoAppManager.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QProcess>
#include <QCoreApplication>
#include <QMessageBox>

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
	nameLabel->setText(QString("<font size=10 color='#9fe070'>%1</font>").arg(_program->name()));
	layoutRight->addWidget(nameLabel);

	QLabel* pathLabel = new QLabel(rightWidget);
	pathLabel->setText(QString("<font size=8 color='#aaaaaa'>%1</font>").arg(_program->path()));
	layoutRight->addWidget(pathLabel);

	QLabel* webLabel = new QLabel(rightWidget);
	webLabel->setOpenExternalLinks(true);
	webLabel->setText(QString("<a href='https://github.com/sololxy'>Contact US</a>").arg(_program->web()));
	layoutRight->addWidget(webLabel);


	layoutRight->addStretch();
	layout->addWidget(rightWidget);

	//layout->addStretch();
	setLayout(layout);

	connect(iconWidget, SIGNAL(pressed()), this, SLOT(openProgram()));
}


SoProgramWidget::~SoProgramWidget()
{

}

void SoProgramWidget::openProgram()
{
	QString programPath = QCoreApplication::applicationDirPath() + _program->path();
	QProcess *process = new QProcess(NULL);
	if (!process->startDetached(programPath)) {
		QMessageBox::warning(this, tr("AppRunner"),
			QString("Cann't open program:\n%1").arg(programPath),QMessageBox::Ok);
	}
}
