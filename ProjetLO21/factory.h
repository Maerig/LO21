#ifndef FACTORY_H
#define FACTORY_H

#include "rationnel.h"

class Factory
{
public:
    Rationnel* make_rationnel(std::string str);
    Donnee* make(std::string str);
};

#endif // FACTORY_H
