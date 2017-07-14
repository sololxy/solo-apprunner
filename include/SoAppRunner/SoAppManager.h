// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_APP_MANAGER_H
#define SO_APP_MANAGER_H

#include <SoAppRunner/SoProgramGroup.h>

/** 程序主管理器，单例模式
 *
 * 负责程序组SoProgramGroup，程序SoProgram的管理
 *
 */
class SO_APPRUNNER_API SoAppManager
{
public:
    SoAppManager* instance();
    ~SoAppManager();


private:
    SoAppManager();

    static SoAppManager* _instance;
};

#endif // SO_APP_MANAGER_H
