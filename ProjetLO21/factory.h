#ifndef FACTORY_H
#define FACTORY_H

#include "donnee.h"
class Factory
{
public:
    Donnee* make(std::string str);
};

#endif // FACTORY_H
