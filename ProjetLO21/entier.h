#ifndef ENTIER_H
#define ENTIER_H

#include "donnee.h"
#include "calculexception.h"

class Entier : public Nombre {
private :
    double val;

public :
    Entier(double v=0) : val(v) {}
    double getVal() {return val;}
    void setVal(double v){val=v;}

    void afficher(std::ostream& f=std::cout) const { f<<val; }
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
