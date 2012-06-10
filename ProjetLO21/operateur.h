#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "donnee.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"
#include "complexe.h"

#include "mainwindow.h"


class Operateur : public Donnee {


public :
    /*void patronDeMethode(Ui::MainWindow MW){

        Calculer(MW);
    }*/

    //virtual void Calculer(Ui::MainWindow MW)=0;

    void patronDeMethode(){

        Calculer();
    }

    virtual void Calculer()=0;

};





#endif // OPERATEUR_H
