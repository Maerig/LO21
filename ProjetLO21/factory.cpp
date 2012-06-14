#include "factory.h"
#include <sstream>
#include "entier.h"
#include "reel.h"
#include "calculexception.h"
#include "pile.h"
#include "operateurbinaire.h"
#include "operateurunaire.h"

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

Reel* Factory::make_reel(std::string str)
{
    if(fraction(str))
    {
        Rationnel* q = make_rationnel(str);
        Reel* r = new Reel(*q);
        delete q;
        return r;
    }
    else
    {
        std::istringstream iss(str);
        float nb;
        iss >> nb;
        return new Reel(nb);
    }
}

Expression* Factory::make_expression(std::string str)
{
    int i=1;
    Cellule* cell=0;    //Derniere cellule courante de la liste chainee en construction
    Cellule* tete=0;
    if(str[0]!='\'')
    {
        throw CalculException("Syntaxe incorrecte.");
        return 0;
    }
    while(str[i] != '\'' && str[i] != '\0')
    {
        std::string tmp;
        while(str[i] != ' ' && str[i] != '\'' && str[i] != '\0')
            tmp += str[i++];
        if(tete==0) //Premier element
        {
            cell = new Cellule(make(tmp));
            tete = cell;
        }
        else
        {
            Cellule* new_cell = new Cellule(make(tmp));
            cell->setSucc(new_cell);
            cell = new_cell;
        }
        while(str[i] == ' ')
            ++i;
    }
    if(str[i] == '\'' && str[i+1] == '\0')
        return  new Expression(tete);
    throw CalculException("Syntaxe incorrecte.");
    return 0;
}

Operateur* Factory::make_operateur(std::string str) //todo
{
    if(str=="+" || str=="-" || str=="*" || str=="/" || str=="MOD" || str=="POW")
        return new OperateurBinaire(str);
/*    else
        return new OperateurUnaire(str);        TODO    */
}

Donnee* Factory::make(std::string str)
{
    std::istringstream iss(str);
    if(str[0]=='\'')
        return make_expression(str);
    else if(number(str))
           {
            if(Donnee::getTypeDonnees()==entier)
            {
                int nb;
                iss >> nb;
                return new Entier(nb);
            }
            else if(Donnee::getTypeDonnees()==reel)
            {
                return make_reel(str);
            }
            else if(Donnee::getTypeDonnees()==rationnel)
            {
                return make_rationnel(str);
            }
           }
        else
        {
            if(operateur_like(str))
                return make_operateur(str);
            throw CalculException("Syntaxe incorrecte.");
        }
    return 0;
}
