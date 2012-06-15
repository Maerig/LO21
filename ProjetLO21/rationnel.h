#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "entier.h"

class Reel;

class Rationnel : public Nombre {
private :
    Entier num;
    Entier denum;



public :
    void simplifier();
    Rationnel(double n=0 , double d=1) : num(n),denum(d) {simplifier();}
    Rationnel(Entier n,Entier d) : num(n),denum(d) {simplifier();}
    Rationnel(Entier e): num(e),denum(1){simplifier();}
    Rationnel(Reel r);

    Entier getNumerateur() {return num;}
    Entier getDenumerateur() {return denum;}

    void afficher(std::ostream& f=std::cout) const { num.afficher(f); f<<"/"; denum.afficher(f); }
    virtual Donnee* clone() const;

    operator float() const {return float(num)/float(denum);}
    Rationnel& operator=(const Rationnel& n);
};



Rationnel operator+( Rationnel& a,  Rationnel& b);
Rationnel operator-( Rationnel& a,  Rationnel& b);
Rationnel operator*( Rationnel& a,  Rationnel& b);
Rationnel operator/( Rationnel& a,  Rationnel& b);
Rationnel operator^( Rationnel& a,  Entier& b);


#endif // RATIONNEL_H
