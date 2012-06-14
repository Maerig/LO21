#include <QtGui/QApplication>
#include "mainwindow.h"
#include "calculexception.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"
#include <iostream>

int main(int argc, char *argv[])
{

    try
    {
    Pile stack;

        QApplication a(argc, argv);
        MainWindow w;
        w.show();
/*
        Reel dA(3.4);
        Reel dB(11.3);

        Reel* A1=&dA;
        Reel* B1=&dB;

        const Reel* test1 = dynamic_cast<const Reel*>(A1);
        const Reel* test2 = dynamic_cast<const Reel*>(B1);


        if ( test1 || test2 ) {

                const Reel A=*test1;
                const Reel B=*test2;
                Reel C(A+B);
                std::cout<<C.getVal();
       }
*/



        return a.exec();

    }
    catch(CalculException exc)
    {
        exc.afficher();
    }
    return 0;
}
