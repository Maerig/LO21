#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    PileD dstack;
    PileA astack;


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
