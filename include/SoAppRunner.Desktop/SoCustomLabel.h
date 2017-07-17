// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_CUSTOM_LABEL_H
#define SO_CUSTOM_LABEL_H

#include <QWidget>
#include <QRgb>
#include <QColor>
#include <QLabel>

#include <SoAppRunner/SoProgram.h>
#include <SoAppRunner.Desktop/SoAppRunnerDesktopExport.h>
#include <SoAppRunner.Desktop/SoCustomWidget.h>

//
class SO_APPRUNNER_DESKTOP_API SoCustomLabel : public QLabel
{
    Q_OBJECT
public:
	SoCustomLabel(QString text="", QWidget* parent = NULL);
    virtual ~SoCustomLabel();

	void setText(QString text);


private:
	QString _originalText;
};

#endif // SO_CUSTOM_LABEL_H
