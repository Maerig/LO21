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


