#ifndef REEL_H
#define REEL_H

#include "rationnel.h"


class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v=0) : val(v) {}
    Reel(Entier e);                                             // Constructeur de Réel �  partir d'un Entier
    Reel(Rationnel r);                                          // Constructeur de Réel �  partir d'un Rationnel

    float getVal() {return val;}
    void afficher(std::ostream& f=std::cout) const { f<<val; }
    virtual Donnee* clone() const;
    operator float() const {return val;}

    Reel& operator=(const Reel& n);
};


Reel operator+( Reel& a,  Reel& b);
Reel operator-( Reel& a,  Reel& b);
Reel operator*( Reel& a,  Reel& b);
Reel operator/( Reel& a,  Reel& b);
Reel operator^( Reel& a,  Entier& b);







#endif // REEL_H
