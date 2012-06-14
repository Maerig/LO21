#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "pile.h"
#include "reel.h"


class Operateur : public Donnee {


public :

    virtual void Calculer(Pile* stack)=0;
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    virtual Donnee* clone() const = 0;
};

bool operateur_like(std::string str);




#endif // OPERATEUR_H
