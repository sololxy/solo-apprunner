#include <SoAppRunner/SoProgram.h>


SoProgram::SoProgram()
{
	_name = "Unknown Program";
	_path = "/none/test.exe";
}

SoProgram::SoProgram(QString name) 
{ 
	_name = name; 
	_path = "/none/test.exe";
};

SoProgram::SoProgram(QString name, QString path, QString desc, QString detailDesc, 
					 QString icon, QString doc, QString web)
{
	_name = name;
	_path = path;
	_desc = desc;
	_detailDesc = detailDesc;
	_icon = icon;
	_doc = doc;
	_web = web;
}

SoProgram::~SoProgram()
{

}
