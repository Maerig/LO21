#include "operateur.h"

bool operateur_like(std::string str)
{
    int i=0;
    while(str[i])
    {
        if(number(str[i]))
            return false;
        ++i;
    }
    return true;
}



