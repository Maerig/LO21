#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "donnee.h"
#include "entier.h"

class Rationnel : public Nombre {
private :
    Entier num;
    Entier denum;



public :
    void simplifier();

    Rationnel(Entier n,Entier d) : num(n),denum(d) {simplifier();}          // Réfléchir au cas où d=0.
    Rationnel(Entier e): num(e),denum(1){simplifier();}                     // ~inutile. Constructeur entier(entier) implicite.

    Entier getNumerateur() {return num;}
    Entier getDenumerateur() {return denum;}

    void afficher(std::ostream& f=std::cout) const { num.afficher(f); f<<"/"; denum.afficher(f); }
    virtual Donnee* clone() const;
};

Rationnel operator+( Rationnel& a,  Rationnel& b);
Rationnel operator-( Rationnel& a,  Rationnel& b);
Rationnel operator*( Rationnel& a,  Rationnel& b);
Rationnel operator/( Rationnel& a,  Rationnel& b);
Rationnel operator^( Rationnel& a,  Entier& b);


#endif // RATIONNEL_H
