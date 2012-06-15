#ifndef FACTORY_H
#define FACTORY_H

#include "rationnel.h"
#include "reel.h"
#include "expression.h"
#include "operateur.h"
#include "complexe.h"

class Factory
{
public:
    Reel* make_reel(std::string str);
    Rationnel* make_rationnel(std::string str);
    Complexe* make_complexe(std::string str);
    Expression* make_expression(std::string str);
    Operateur* make_operateur(std::string str);
    Donnee* make(std::string str);

};

#endif // FACTORY_H
