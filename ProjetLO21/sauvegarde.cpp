#include "sauvegarde.h"
#include <fstream>
#include <iostream>
#include <string>
#include "calculexception.h"
#include "donnee.h"
#include "factory.h"

void sauver_contexte(std::string name,Pile* stack)
{
    std::ofstream f(name.c_str(), std::ios::out | std::ios::trunc);    //Ouverture du fichier en ecriture
    if(f)
    {
        f<<"[Parametres]\n";
        f<<"typedonnees="<<Donnee::getTypeDonnees()<<"\n";
        f<<"typecomplexe="<<Donnee::getTypeComplexe()<<"\n";
        f<<"typeangle="<<Donnee::getTypeAngles()<<"\n";
        f<<"[Pile]\n";
        stack->clone()->affichage_inverse(f);
        f.close();
    }
    else
        throw CalculException("Ouverture du fichier impossible.");
}

void charger_contexte(std::string name, Pile *stack)
{
    std::ifstream f(name.c_str(), std::ios::in);    //Ouverture du fichier en lecture
    std::string str;
    Factory fact;
    if(f)
    {
        while(getline(f,str))
        {
            if(str=="[Parametres]")
            {
                getline(f,str);Donnee::setTypeDonnees(get_value(str));
                getline(f,str);Donnee::setTypeComplexe(get_value(str));
                getline(f,str);Donnee::setTypeAngle(get_value(str));
            }
            else if(str=="[Pile]")
                while(getline(f,str))
                    stack->empiler(fact.remake(str));
                else
                    throw CalculException("Fichier corrompu.");
        }
        f.close();
    }
    else
        throw CalculException("Ouverture du fichier impossible.");
}

int get_value(std::string ligne)
{
    return ligne[ligne.length()-1] - '0';
}
