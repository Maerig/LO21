#include <QtGui/QApplication>
#include "mainwindow.h"
#include "calculexception.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"

int main(int argc, char *argv[])
{
    try
    {
    Pile stack;

        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        /*Entier b(5);
        Rationnel c(3);
        Rationnel d(c+b);*/
        return a.exec();

    }
    catch(CalculException exc)
    {
        std::cout<<exc.getInfo()<<"\n";
    }
    return 0;
}
