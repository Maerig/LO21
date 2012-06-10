#ifndef FACTORY_H
#define FACTORY_H

#include "rationnel.h"
#include "reel.h"

class Factory
{
public:
    Reel* make_reel(std::string str);
    Rationnel* make_rationnel(std::string str);
    Donnee* make(std::string str);
};

#endif // FACTORY_H
