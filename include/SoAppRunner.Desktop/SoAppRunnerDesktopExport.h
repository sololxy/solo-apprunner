// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_APP_RUNNER_DESKTOP_EXPORT_H
#define SO_APP_RUNNER_DESKTOP_EXPORT_H

#ifdef _WIN32
# ifdef BUILDING_APPRUNNER_DESKTOP_API
#   define SO_APPRUNNER_DESKTOP_API __declspec(dllexport)
# else
#   define SO_APPRUNNER_DESKTOP_API __declspec(dllimport)
# endif
#else
# define SO_APPRUNNER_DESKTOP_API /* nothing */
#endif

#endif // SO_APP_RUNNER_DESKTOP_EXPORT_H
