#include "factory.h"
#include <sstream>

Donnee* Factory::make(std::string str)
{
    std::istringstream iss(str);
    if(Donnee::getTypeDonnees()==entier)
    {
        int nb;
        iss >> nb;
        return new Entier(nb);
    }
    else
        return 0;   // à enlever
}
