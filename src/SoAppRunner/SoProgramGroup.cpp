#include <SoAppRunner/SoProgramGroup.h>

SoProgramGroup::SoProgramGroup()
{
	_name = "Unknown Group";
}

SoProgramGroup::SoProgramGroup(QString name)
{
	_name = name;
}

SoProgramGroup::~SoProgramGroup()
{

	for (int i = 0; i < _programs.size(); i++) {
		SoProgram* program = _programs[i];

		if (NULL != program) delete program;
	}

	_programs.clear();
}
