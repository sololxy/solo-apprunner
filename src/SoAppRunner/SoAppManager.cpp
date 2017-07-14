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

	return true;
}
