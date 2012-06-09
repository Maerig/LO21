#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "donnee.h"

class Rationnel : public Nombre {
private :
    double num;
    double denum;

public :
    Rationnel(double n,double d) : num(n),denum(d) {}
    void afficher(std::ostream& f=std::cout) const { f<<num<<"/"<<denum; }
};

#endif // RATIONNEL_H
