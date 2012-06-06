#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "donnee.h"

class Complexe : public Numerique {
private :
    Nombre a;
    Nombre b;

public :
    Complexe(Nombre Re, Nombre Im) : a(Re),b(Im) {}

};


#endif // COMPLEXE_H
