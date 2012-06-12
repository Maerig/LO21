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

    void patronDeMethode(Pile* stack){

        Calculer(stack);
    }

    virtual void Calculer(Pile* stack)=0;

};

void Unifier(Donnee &A, Donnee &B, Pile* stack);



#endif // OPERATEUR_H
