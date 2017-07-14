#include <SoAppRunner/SoAppManager.h>

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

bool SoAppManager::open(QString configPath)
{
	/*
	QXmlStreamReader xmlReader(configPath);
	while (!xmlReader.atEnd() && !xmlReader.hasError())
	{
		xmlReader.readNext();
		if (xmlReader.isStartElement())
		{

			if (xmlReader.name() == "titile")
			{
				setName(xmlReader.readElementText());

			}else if(xmlReader.name() == "ProgramGroup") {

				QXmlStreamAttributes attributes = xmlReader.attributes();
				QString groupName;
				if (attributes.hasAttribute("name"))
					groupName = attributes.value("id").toString();

				//if (reader.name() == "Number")

			}
		}

	}
	*/

	SoProgramGroup * group1 = new SoProgramGroup();
	SoProgram *program1 = new SoProgram("program1");
	SoProgram *program2 = new SoProgram("program2");
	SoProgram *program3 = new SoProgram("program3");
	group1->programs().push_back(program1);
	group1->programs().push_back(program2);
	group1->programs().push_back(program3);
	_groups.push_back(group1);

	SoProgramGroup * group2 = new SoProgramGroup();
	SoProgram *program4 = new SoProgram("program4");
	SoProgram *program5 = new SoProgram("program5");
	group2->programs().push_back(program4);
	group2->programs().push_back(program5);
	_groups.push_back(group2);

	return true;
}
