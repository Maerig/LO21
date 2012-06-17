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
    Entier* make_entier(std::string str);
    Reel* make_reel(std::string str);
    Rationnel* make_rationnel(std::string str);
    Complexe* make_complexe(std::string str);
    Complexe* remake_complexe(std::string str);
    Expression* make_expression(std::string str);
    Expression* remake_expression(std::string str);
    Operateur* make_operateur(std::string str);
    Donnee* make(std::string str);
    Donnee* remake(std::string str);

};

#endif // FACTORY_H
