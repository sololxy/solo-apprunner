// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_PROGRAM_H
#define SO_PROGRAM_H

#include <QString>

#include <SoAppRunner/SoAppRunnerExport.h>

// 单个程序
class SO_APPRUNNER_API SoProgram
{
public:
	SoProgram();
	SoProgram(QString name);
	SoProgram(QString name, QString path, QString desc, QString detailDesc,
			  QString icon, QString doc, QString web);
	virtual ~SoProgram();


	// 程序名
	QString name() { return _name; };
	void setName(QString name) { _name = name; }

	// 程序路径，相对目录
	QString path() { return _path; };
	void setPath(QString path) { _path = path; }

	// 程序简要描述
	QString desc() { return _desc; };
	void setDesc(QString desc) { _desc = desc; }

	// 程序详细介绍
	QString detailDesc() { return detailDesc(); };
	void setDetailDesc(QString detailDesc) { _detailDesc = detailDesc; }

	// 程序icon,png格式 120x120 pix
	QString icon() { return _icon; };
	void setIcon(QString icon) { _icon = icon; }

	// 程序文档位置，相对目录或网址
	QString doc() { return _doc; };
	void setDoc(QString doc) { _doc = doc; }

	// 程序网址
	QString web() { return _web; };
	void setWeb(QString web) { _web = web; }
private:
	QString _name;
	QString _path;
	QString _desc;
	QString _detailDesc;
	QString _icon;
	QString _doc;
	QString _web;
};

#endif // SO_PROGRAM_H
