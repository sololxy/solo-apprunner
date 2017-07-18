// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_PROGRAM_GROUP_H
#define SO_PROGRAM_GROUP_H

#include <vector>

using namespace std;

#include <SoAppRunner/SoProgram.h>

// 功能相关的几个程序的组合
class SO_APPRUNNER_API SoProgramGroup
{
public:
    SoProgramGroup();
    SoProgramGroup(QString name);
    virtual ~SoProgramGroup();

    // 程序组名
    QString name() { return _name; };
	void setName(QString name) { _name = name; }
    vector<SoProgram*>& programs() { return _programs; };

private:
    vector<SoProgram*> _programs;
    QString _name;
};

#endif // SO_PROGRAM_GROUP_H
