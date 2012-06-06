#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "donnee.h"

class Rationnel : public Nombre {
private :
    double num;
    double denum;

public :
    Rationnel(double n,double d) : num(n),denum(d) {}

};

#endif // RATIONNEL_H
