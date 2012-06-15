#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "donnee.h"

class Complexe : public Numerique {
private :
    Nombre* a;
    Nombre* b;

public :
    Complexe(Nombre* Re=0, Nombre* Im=0) : a(Re),b(Im) {}

    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};


#endif // COMPLEXE_H
