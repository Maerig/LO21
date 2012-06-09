#ifndef ENTIER_H
#define ENTIER_H

#include "donnee.h"

class Entier : public Nombre {
private :
    double val;                         // pourquoi pas unsigned long int

public :
    Entier(double v) : val(v) {}
    double getVal() {return val;}
    void afficher(std::ostream& f=std::cout) const { f<<val; }

};


Entier operator+( Entier& a,  Entier& b);
Entier operator-( Entier& a,  Entier& b);
Entier operator*( Entier& a,  Entier& b);
Entier operator/( Entier& a,  Entier& b);
Entier operator%( Entier& a,  Entier& b);
Entier operator^( Entier& a,  Entier& b);


#endif // ENTIER_H
