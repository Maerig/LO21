#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "pile.h"


class Operateur : public Donnee {


public :

    void patronDeMethode(Pile* stack){

        Calculer(stack);
    }

    virtual void Calculer(Pile* stack)=0;

};

bool operateur_like(std::string str);
void Unifier(Donnee &A, Donnee &B, Pile* stack);



#endif // OPERATEUR_H
