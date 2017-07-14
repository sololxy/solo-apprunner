// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_APP_MANAGER_H
#define SO_APP_MANAGER_H

#include <vector>

using namespace std;

#include <SoAppRunner/SoProgramGroup.h>

/** 程序主管理器，单例模式
 *
 * 负责程序组SoProgramGroup，程序SoProgram的管理
 *
 */
class SO_APPRUNNER_API SoAppManager
{
public:
    static SoAppManager* instance();
    ~SoAppManager();

    bool open(QString configPath);

    void setName(QString name) { _name = name; }
    QString name() { return _name; }

    vector<SoProgramGroup*>& groups() { return _groups; };

private:
    SoAppManager();

    static SoAppManager* _instance;
    QString _configPath;
    QString _name;
    vector<SoProgramGroup*> _groups;
};

#endif // SO_APP_MANAGER_H
