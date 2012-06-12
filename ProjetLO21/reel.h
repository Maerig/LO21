#ifndef REEL_H
#define REEL_H

#include "entier.h"
#include "rationnel.h"

class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v) : val(v) {}
    Reel(Entier e);                                             // Constructeur de RÃ©el Ã  partir d'un Entier
    Reel(Rationnel r);                                          // Constructeur de RÃ©el Ã  partir d'un Rationnel

    float getVal() {return val;}
    void afficher(std::ostream& f=std::cout) const { f<<val; }
    virtual Donnee* clone() const;
};


Reel operator+( Reel& a,  Reel& b);
Reel operator-( Reel& a,  Reel& b);
Reel operator*( Reel& a,  Reel& b);
Reel operator/( Reel& a,  Reel& b);
Reel operator^( Reel& a,  Entier& b);


#endif // REEL_H
