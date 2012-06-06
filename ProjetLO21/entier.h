#ifndef ENTIER_H
#define ENTIER_H

#include "donnee.h"

class Entier : public Nombre {
private :
    double val;

public :
    Entier(double v) : val(v) {}

};

#endif // ENTIER_H
