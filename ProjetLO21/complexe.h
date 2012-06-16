#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "donnee.h"
#include "reel.h"

class Complexe : public Numerique {
private :
    Nombre* a;
    Nombre* b;

public :
    Complexe(Nombre* Re, Nombre* Im) : a(Re),b(Im) {}
    Complexe(Donnee* Re, Donnee* Im);
    Complexe(Donnee* Re);
    Complexe();

    Complexe& operator=(const Complexe& n);
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};

bool complexe_like(std::string str);

#endif // COMPLEXE_H
