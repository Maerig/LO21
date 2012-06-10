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
};


Entier operator+( Entier& a,  Entier& b);
Entier operator-( Entier& a,  Entier& b);
Entier operator*( Entier& a,  Entier& b);
Entier operator/( Entier& a,  Entier& b);
Entier operator%( Entier& a,  Entier& b);
Entier operator^( Entier& a,  Entier& b);


#endif // ENTIER_H
