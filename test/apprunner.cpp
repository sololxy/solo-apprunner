#include <QApplication>
#include <QWidget>
//#include <SoAppManagerWidgets>

int main(int argn, char** argv)
{
    QApplication app(argn,argv);
    QWidget w;

    w.show();

    return app.exec();
}
