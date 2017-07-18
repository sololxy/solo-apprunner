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

			while (!xmlReader.atEnd()) {
				xmlReader.readNext();
				if (xmlReader.isStartElement()) {
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
				}

				if (xmlReader.isEndElement()) {
					if (xmlReader.name() == "Path")
						continue;
					else if (xmlReader.name() == "Icon")
						continue;
					else if (xmlReader.name() == "Desc")
						continue;
					else if (xmlReader.name() == "DetailDesc")
						continue;
					else if (xmlReader.name() == "Doc")
						continue;
					else if (xmlReader.name() == "Web")
						continue;
					else break;
				}
			}

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
	
	return true;
}
