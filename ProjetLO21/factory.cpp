#include "factory.h"
#include <sstream>
#include "entier.h"
#include "reel.h"


Donnee* Factory::make(std::string str)
{
    std::istringstream iss(str);
    if(Donnee::getTypeDonnees()==entier)
    {
        int nb;
        iss >> nb;
        return new Entier(nb);
    }
    else if(Donnee::getTypeDonnees()==reel)
    {
        float nb;
        iss >> nb;
        return new Reel(nb);
    }
    else if(Donnee::getTypeDonnees()==rationnel)
    {


    }

    else


        return 0;   // à enlever
}
