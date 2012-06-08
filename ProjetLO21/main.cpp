#include <QtGui/QApplication>
#include "mainwindow.h"
#include "calculexception.h"

int main(int argc, char *argv[])
{
    try
    {
    Pile stack;


        QApplication a(argc, argv);
        MainWindow w;
        w.show();


        return a.exec();
    }
    catch(CalculException exc)
    {

    }
}
