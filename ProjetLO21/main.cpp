#include <QtGui/QApplication>
#include "mainwindow.h"
#include "calculexception.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"
#include <iostream>
#include <math.h>

int main(int argc, char *argv[])
{

    try
    {
    Pile stack;

        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        Reel A(90);

        A=Reel(sin(A.getVal()));

        std::cout<<"HOUHOU \n"<<A.getVal();


        return a.exec();

    }
    catch(CalculException exc)
    {
        exc.afficher();
    }
    return 0;
}
