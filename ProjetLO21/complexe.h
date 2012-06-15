#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "donnee.h"

class Complexe : public Numerique {
private :
    Nombre* a;
    Nombre* b;

public :
    Complexe(Nombre* Re, Nombre* Im) : a(Re),b(Im) {}
    Complexe(Donnee* Re, Donnee* Im);

    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};

bool complexe_like(std::string str);

#endif // COMPLEXE_H
