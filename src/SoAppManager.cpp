#include <SoAppManager.h>

SoAppManager* SoAppManager::_instance = NULL;


SoAppManager::SoAppManager()
{

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
