#include <SoAppRunner.Desktop/SoProgramWidget.h>
#include <SoAppRunner/SoAppManager.h>
#include <SoAppRunner.Desktop/SoCustomLabel.h>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
//#include <QProcess>
#include <QCoreApplication>
#include <QMessageBox>

SoProgramWidget::SoProgramWidget(QWidget* parent, SoProgram* program)
    : SoCustomWidget(QColor(0xFF,0xFF,0xFF),parent), _program(program)
{
	setContentsMargins(0, 0, 0, 0);

	QHBoxLayout* layout = new QHBoxLayout();
	//layout->setContentsMargins(10, 10, 10, 10);
	
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
	rightWidget->setMinimumWidth(300);
	rightWidget->setContentsMargins(0, 0, 0, 0);
	QVBoxLayout* layoutRight = new QVBoxLayout();
	layoutRight->setContentsMargins(0, 0, 0, 0);
	rightWidget->setLayout(layoutRight);
	
	QLabel* nameLabel = new QLabel(rightWidget);
	nameLabel->setText(QString("<font size=5 color='green'>%1</font>")
							 .arg(_program->name()));
	layoutRight->addWidget(nameLabel);

	QLabel* pathLabel = new QLabel(rightWidget);
	pathLabel->setText(QString("<font size=4>%1</font>")
								.arg(_program->path()));
	layoutRight->addWidget(pathLabel);

	SoCustomLabel* webLabel = new SoCustomLabel();
	webLabel->setOpenExternalLinks(true);
	webLabel->setText(QString("<font size=4><a href='https://github.com/sololxy'>\
								Contact US</a></font>"));
	layoutRight->addWidget((QWidget*)webLabel);


	layoutRight->addStretch();
	layout->addWidget(rightWidget);

	layout->addStretch();
	setLayout(layout);

	connect(iconWidget, SIGNAL(pressed()), this, SLOT(openProgram()));
}


SoProgramWidget::~SoProgramWidget()
{

}

void SoProgramWidget::openProgram()
{
	QString programPath = QCoreApplication::applicationDirPath() 
					    + _program->path();
	/*QProcess *process = new QProcess(NULL);
	if (!process->startDetached(programPath)) {
		QMessageBox::warning(this, tr("AppRunner"),
							QString("Cann't open program:\n%1").arg(programPath),
							QMessageBox::Ok);
	}*/
}
