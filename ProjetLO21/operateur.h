#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "pile.h"
#include "reel.h"
#include "calculexception.h"
#include "complexe.h"

class Operateur : public Donnee {


public :

    virtual void Calculer(Pile* stack)=0;
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    void afficher_contexte(std::ostream &f) const { f<<"Operateur:";afficher(f); }
    virtual Donnee* clone() const = 0;
};

bool operateur_like(std::string str);




#endif // OPERATEUR_H
