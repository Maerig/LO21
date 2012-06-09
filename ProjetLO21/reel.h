#ifndef REEL_H
#define REEL_H

#include "donnee.h"

class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v) : val(v) {}
    void afficher(std::ostream& f=std::cout) const { f<<val; }
};

#endif // REEL_H
