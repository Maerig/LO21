#ifndef ENTIER_H
#define ENTIER_H

#include "donnee.h"
#include "calculexception.h"

class Entier : public Nombre {
private :
    long int val;

public :
    Entier(double v=0) : val(v) {}
    double getVal() const {return val;}
    void setVal(double v){val=v;}

    virtual void setSign() {val=(-val);}

    void afficher(std::ostream& f=std::cout) const { f<<val; }
    void afficher_contexte(std::ostream& f) const { f<<"Entier:"<<val; }
    Donnee* clone() const;

    operator float() const {return float(val);}
    Entier& operator=(const Entier& n);
};


Entier operator+( Entier  &a,  Entier  &b);
Entier operator-( Entier  &a,  Entier  &b);
Entier operator*( Entier  &a,  Entier  &b);
Entier operator/( Entier  &a,  Entier  &b);
Entier operator%( Entier  &a,  Entier  &b);
Entier operator^( Entier  &a,  Entier  &b);


#endif // ENTIER_H
