#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "pile.h"
#include "reel.h"


class Operateur : public Donnee {


public :

    virtual void Calculer(Pile* stack)=0;

};

bool operateur_like(std::string str);

void Unifier(Donnee &A, Donnee &B);



#endif // OPERATEUR_H
