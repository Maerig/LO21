#include "sauvegarde.h"
#include <fstream>
#include <iostream>
#include <string>
#include "calculexception.h"

void sauver_contexte(std::string name)
{
    std::ofstream f(name.c_str(), std::ios::out | std::ios::trunc);    //Ouverture du fichier en ecriture
    if(f)
    {
        f<<"Test";

        f.close();
    }
    else
        throw CalculException("Ouverture du fichier impossible.");
}





void charger_contexte(std::string name)
{
    std::ifstream f(name.c_str(), std::ios::in);    //Ouverture du fichier en lecture
    if(f)
    {

        f.close();
    }
    else
        throw CalculException("Ouverture du fichier impossible.");
}
