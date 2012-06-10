#include "factory.h"
#include <sstream>
#include "entier.h"
#include "reel.h"


Rationnel* Factory::make_rationnel(std::string str)
{
    int i=0;
    int num = 0,denum = 1;
    std::string tmp, num_str, denum_str;
    while(str[i] != '\0' && str[i] != '/')
        num_str += str[i++];
    std::istringstream num_iss(num_str);
    num_iss >> num;
    if(str[i]=='/')
    {
        i++;
        while(str[i] != '\0')
            denum_str += str[i++];
        std::istringstream denum_iss(denum_str);
        denum_iss >> denum;
    }
            return new Rationnel(num,denum);
}

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
        return make_rationnel(str);
    }

    else


        return 0;   // à enlever
}
