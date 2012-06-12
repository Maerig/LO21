#include "donnee.h"
#include "calculexception.h"

/* Initialisation des paramètres */
bool Donnee::expression = false;
TypeDonnee Donnee::typedonnees = entier;
bool Donnee::typecomplexe = false;
TypeAngle Donnee::typeangles = degre;


void Donnee::setTypeDonnees(std::string type){
    if(type == "Entier")
    {
        typedonnees = entier;
    }
    else if(type == "Rationnel")
        {
            typedonnees = rationnel;
        }
        else if(type == "Reel")
            {
        typedonnees = reel;
            }
            else
                throw CalculException("Type inconnu.");

}


bool fraction(std::string str)
{
    int i=0;
    while(str[i] != '/' && str[i] != '\0')
        i++;
    if(str[i] == '/')
        return true;
    else
        return false;
}



