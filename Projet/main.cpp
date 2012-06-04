#include <QtGui/QApplication>
#include "mainwindow.h"
#include "donnee.h"
#include "pile.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /* Test */
    PileD dstack;
    Entier data(24);
    Donnee* dataptr;
    dstack.empiler(&data);
    dataptr = dstack.depiler();


    w.show();

    return a.exec();
}


