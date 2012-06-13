#ifndef ENTIER_H
#define ENTIER_H

#include "donnee.h"

class Entier : public Nombre {
private :
    double val;

public :
    Entier(double v) : val(v) {}
    double getVal() {return val;}
    void setVal(double v){val=v;}

    void afficher(std::ostream& f=std::cout) const { f<<val; }
    Donnee* clone() const;

    operator float() const {return float(val);}
};


Entier operator+( Entier const &a,  Entier const &b);
Entier operator-( Entier const &a,  Entier const &b);
Entier operator*( Entier const &a,  Entier const &b);
Entier operator/( Entier const &a,  Entier const &b);
Entier operator%( Entier const &a,  Entier const &b);
Entier operator^( Entier const &a,  Entier const &b);


#endif // ENTIER_H
