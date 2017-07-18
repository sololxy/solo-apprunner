#include <SoAppRunner/SoAppManager.h>

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamAttributes>

SoAppManager* SoAppManager::_instance = NULL;


SoAppManager::SoAppManager()
{
	_name = "SoAppRunner";
}


SoAppManager::~SoAppManager()
{
	for (int i = 0; i < _groups.size(); i++) {
		SoProgramGroup* group = _groups[i];

		if (NULL != group) delete group;
	}

	_groups.clear();
}

SoAppManager* SoAppManager::instance()
{
	if (NULL == _instance) {
		_instance = new SoAppManager();
	}

	return _instance;
}

SoProgram* SoAppManager::readProgram(QXmlStreamReader& xmlReader, SoProgramGroup* group)
{
	SoProgram* program = new SoProgram();
	QString programName;
	QXmlStreamAttributes attributesProgram = xmlReader.attributes();

	if (attributesProgram.hasAttribute("name")) {
		programName = attributesProgram.value("name").toString();
		program->setName(programName);
	}

	while (!xmlReader.atEnd()) {
		xmlReader.readNext();

		if (xmlReader.isStartElement()) {
			QString path, icon, desc, detailDesc,doc,web;

			if (xmlReader.name() == "Path")
				path = xmlReader.readElementText();
			else if (xmlReader.name() == "Icon")
				icon = xmlReader.readElementText();
			else if (xmlReader.name() == "Desc")
				desc = xmlReader.readElementText();
			else if (xmlReader.name() == "DetailDesc")
				detailDesc = xmlReader.readElementText();
			else if (xmlReader.name() == "Doc")
				doc = xmlReader.readElementText();
			else if (xmlReader.name() == "Web")
				web = xmlReader.readElementText();

			program->setPath(path);
			program->setIcon(icon);
			program->setDesc(desc);
			program->setDetailDesc(detailDesc);
			program->setDoc(doc);
			program->setWeb(web);

		}


		if (xmlReader.isEndElement()) {
			if (xmlReader.name() == "Program") {
				break;
			}
		}
	}

	return program;

}

SoProgramGroup* SoAppManager::readProgramGroup(QXmlStreamReader& xmlReader)
{
	QString groupName;
	SoProgramGroup* group = new SoProgramGroup();
	QXmlStreamAttributes attributesGroup = xmlReader.attributes();

	if (attributesGroup.hasAttribute("name")) {
		groupName = attributesGroup.value("name").toString();
		group->setName(groupName);
	}

	while (!xmlReader.atEnd()) {
		xmlReader.readNext();

		if (xmlReader.isStartElement()) {
			if (xmlReader.name() == "Program") {
				SoProgram* program = readProgram(xmlReader, group);
				group->programs().push_back(program);
			}
		}

		if (xmlReader.isEndElement()) {
			if (xmlReader.name() == "ProgramGroup") {
				break;
			}
		}

	}

	return group;
}

bool SoAppManager::open(QString configPath)
{
	
	QFile xmlFile(configPath);

	if (!xmlFile.open(QIODevice::Text|QIODevice::ReadOnly))
		return false;

	QXmlStreamReader xmlReader(&xmlFile);

	// 读ProgramGroup and Title
	while (!xmlReader.atEnd())
	{
		xmlReader.readNext();		

		if (xmlReader.isStartElement()) {

			if (xmlReader.name() == "AppRunner") {

				QXmlStreamAttributes attributes = xmlReader.attributes();
				QString appName;
				if (attributes.hasAttribute("name")) {
					appName = attributes.value("name").toString();
					setName(appName);
				}
			}

			QString groupName;
			if (xmlReader.name() == "ProgramGroup") {
				SoProgramGroup* group = readProgramGroup(xmlReader);
				this->groups().push_back(group);
			}
		}


		
	}

	xmlFile.close();
	

	/*SoProgramGroup * group2 = new SoProgramGroup(QStringLiteral("航线设计"));
	SoProgram *program4 = new SoProgram("program4");
	SoProgram *program5 = new SoProgram("program5");
	group2->programs().push_back(program4);
	group2->programs().push_back(program5);
	_groups.push_back(group2);

	SoProgramGroup * group4 = new SoProgramGroup(QStringLiteral("质量检查"));
	SoProgram *program7 = new SoProgram("TOPCheck");
	group4->programs().push_back(program7);
	_groups.push_back(group4);

	SoProgramGroup * group1 = new SoProgramGroup(QStringLiteral("数据处理"));
	SoProgram *program1 = new SoProgram("program1");
	SoProgram *program2 = new SoProgram("program2");
	SoProgram *program3 = new SoProgram("program3");
	group1->programs().push_back(program1);
	group1->programs().push_back(program2);
	group1->programs().push_back(program3);
	_groups.push_back(group1);


	SoProgramGroup * group5 = new SoProgramGroup(QStringLiteral("视频处理"));
	SoProgram *program8 = new SoProgram("TOPVideo");
	group5->programs().push_back(program8);
	_groups.push_back(group5);

	SoProgramGroup * group3 = new SoProgramGroup(QStringLiteral("辅助工具"));
	SoProgram *program6 = new SoProgram("Data Checker");
	group3->programs().push_back(program6);
	_groups.push_back(group3);*/

	return true;
}
