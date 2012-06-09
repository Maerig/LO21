#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "donnee.h"
#include "entier.h"

class Rationnel : public Nombre {
private :
    double num;
    double denum;



public :
    void simplifier();

    Rationnel(double n,double d) : num(n),denum(d) {simplifier();}          // Réfléchir au cas où d=0.
    Rationnel(Entier e);

    double getNumerateur() {return num;}
    double getDenumerateur() {return denum;}



    void afficher(std::ostream& f=std::cout) const { f<<num<<"/"<<denum; }
};

Rationnel operator+( Rationnel& a,  Rationnel& b);
Rationnel operator-( Rationnel& a,  Rationnel& b);
Rationnel operator*( Rationnel& a,  Rationnel& b);
Rationnel operator/( Rationnel& a,  Rationnel& b);
Rationnel operator^( Rationnel& a,  Entier& b);


#endif // RATIONNEL_H
