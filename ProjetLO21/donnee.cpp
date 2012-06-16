#include "donnee.h"
#include "calculexception.h"

/* Initialisation des paramètres */
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

void Donnee::setTypeDonnees(int i)
{
    switch(i)
    {
        case 0 : typedonnees = entier; break;
        case 1 : typedonnees = rationnel; break;
        case 2 : typedonnees = reel; break;
        default : throw CalculException("Type de donnee non reconnu."); break;
    }
}

void Donnee::setTypeAngle(int i)
{
    switch(i)
    {
        case 0 : typeangles = degre; break;
        case 1 : typeangles = radian; break;
    default : throw CalculException("Type d'angle non reconnu."); break;
    }
}

bool number(char c)
{
    if(c >='0' && c <= '9')
        return true;
    return false;
}

bool number(std::string str)
{
    int i=0;
    while(str[i])
    {

        if(number(str[i]) || ((str[i]=='/' || str[i]=='.') && i>0 && number(str[i-1]) && number(str[i+1])))
            ++i;
        else
            return false;
    }
    return true;
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
