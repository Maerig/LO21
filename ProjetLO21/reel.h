#ifndef REEL_H
#define REEL_H

#include "donnee.h"
#include "entier.h"
#include "rationnel.h"

class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v) : val(v) {}
    Reel(Entier e);                                             // Constructeur de Réel à partir d'un Entier
    Reel(Rationnel r);                                          // Constructeur de Réel à partir d'un Rationnel

    float getVal() {return val;}
    void afficher(std::ostream& f=std::cout) const { f<<val; }
};


Reel operator+( Reel& a,  Reel& b);
Reel operator-( Reel& a,  Reel& b);
Reel operator*( Reel& a,  Reel& b);
Reel operator/( Reel& a,  Reel& b);
Reel operator^( Reel& a,  Entier& b);


#endif // REEL_H
