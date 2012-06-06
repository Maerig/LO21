#ifndef REEL_H
#define REEL_H

#include "donnee.h"

class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v) : val(v) {}

};

#endif // REEL_H
