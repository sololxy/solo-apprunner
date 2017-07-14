// Copyright luoxiangyong, E-mail: solo_lxy@126.com
// https://github.com/sololxy/solo-apprunner.git
// $Id$

#ifndef SO_PROGRAM_H
#define SO_PROGRAM_H

// 单个程序
class SoProgram
{
public:
    SoProgram();
    virtual ~SoProgram();

    // 程序路径，相对目录
    QString path();

    // 程序简要描述
    QString desc();

    // 程序详细介绍
    QString detailDesc();

    // 程序icon,png格式 120x120 pix
    QString icon();

    // 程序文档位置，相对目录或网址
    QString doc();

    // 程序网址
    QString web();

private:
    QString _path;
    QString _desc;
    QString _detailDesc;
    QString _icon;
    QString _doc;
    QString _web;
};

#endif // SO_PROGRAM_H
