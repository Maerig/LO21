#include "factory.h"
#include <sstream>
#include "entier.h"
#include "reel.h"
#include "calculexception.h"
#include "pile.h"
#include "operateurbinaire.h"
#include "operateurunaire.h"

Entier* Factory::make_entier(std::string str)
{
    std::istringstream iss(str);
    int nb;
    iss >> nb;
    return new Entier(nb);
}

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

    if (denum==0)throw CalculException("Fraction avec denominateur nul impossible.");
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

Complexe* Factory::make_complexe(std::string str)
{
    int i=0;
    Complexe* z;
    std::string re,im;
    if(!Donnee::getTypeComplexe())
    {
        throw CalculException("On ne peut creer des complexes qu'en mode complexe.");
        return 0;
    }
    if(!complexe_like(str))
    {
        throw CalculException("Erreur de syntaxe.");
        return 0;
    }
    while(str[i]&&str[i]!='$')
        re+=str[i++];
    ++i;
    while(str[i])
        im+=str[i++];
    Donnee::setTypeComplexe(false); //Permet de ne pas recreer de complexe a partir des nombres simples
    z = new Complexe(make(re),make(im));
    Donnee::setTypeComplexe(true);
    return z;
}

Complexe* Factory::remake_complexe(std::string str)
{
    int i=0;
    std::string re,im;
    while(str[i]&&str[i]!='+')
        re+=str[i++];
    ++i;
    while(str[i] && !(str[i]=='i'&&str[i+1]=='\0'))
        im+=str[i++];
    return new Complexe(remake(re),remake(im));
}

Expression* Factory::make_expression(std::string str)
{
    int i=1,n=0;
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
        ++n;
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
        return  new Expression(tete,n);
    throw CalculException("Syntaxe incorrecte.");
    return 0;
}

Expression* Factory::remake_expression(std::string str)
{
    int i=1,n=0;
    Cellule* cell=0;    //Derniere cellule courante de la liste chainee en construction
    Cellule* tete=0;
    if(str[0]!='\'')
    {
        throw CalculException("Fichier corrompu.");
        return 0;
    }
    while(str[i] != '\'' && str[i] != '\0')
    {
        std::string tmp;
        while(str[i] != ' ' && str[i] != '\'' && str[i] != '\0')
            tmp += str[i++];
        ++n;
        if(tete==0) //Premier element
        {
            cell = new Cellule(remake(tmp));
            tete = cell;
        }
        else
        {
            Cellule* new_cell = new Cellule(remake(tmp));
            cell->setSucc(new_cell);
            cell = new_cell;
        }
        while(str[i] == ' ')
            ++i;
    }
    if(str[i] == '\'' && str[i+1] == '\0')
        return  new Expression(tete,n);
    throw CalculException("Fichier corrompu.");
    return 0;

}

Operateur* Factory::make_operateur(std::string str)
{
    // Construction du type de l'operateur a partir du string entree.
    if(str=="+") return new OperateurBinaire(PLUS);

    else if(str=="-") return new OperateurBinaire(MINUS);

    else if(str=="*") return new OperateurBinaire(MULT);

    else if(str=="/") return new OperateurBinaire(DIV);

    else if(str=="MOD") return new OperateurBinaire(MODULO);

    else if(str=="^") return new OperateurBinaire(POW);

    else if(str=="SIN") return new Sinus();

    else if(str=="COS") return new Cosinus();

    else if(str=="TAN") return new Tang();

    else if(str=="SINH") return new Sinush();

    else if(str=="COSH") return new Cosinush();

    else if(str=="TANH") return new Tangh();

    else if(str=="SQR") return new Sqr();

    else if(str=="SQRT") return new Sqrt();

    else if(str=="CUBE") return new Cube();

    else if(str=="LN") return new Ln();

    else if(str=="LOG") return new Log();

    else if(str=="!") return new Fact();

    else if(str=="INV") return new Inv();

    else if(str=="SIGN") return new Sign();

    throw CalculException("Operateur inconnu.");

}

Donnee* Factory::make(std::string str)
{
    if(str[0]=='\'')
        return make_expression(str);
    else if(number(str))
           {
            if(Donnee::getTypeDonnees()==entier)
            {
                if(Donnee::getTypeComplexe())
                    return new Complexe(make_entier(str),new Entier);
                return make_entier(str);
            }
            else if(Donnee::getTypeDonnees()==reel)
            {
                if(Donnee::getTypeComplexe())
                    return new Complexe(make_reel(str),new Reel);
                return make_reel(str);
            }
            else if(Donnee::getTypeDonnees()==rationnel)
            {
                if(Donnee::getTypeComplexe())
                    return new Complexe(make_rationnel(str),new Rationnel);
                return make_rationnel(str);
            }
           }
        else
        {
            if(operateur_like(str))
                return make_operateur(str);
            if(complexe_like(str))
                if(Donnee::getTypeComplexe())
                    return make_complexe(str);
                else
                    throw CalculException("On ne peut creer des complexes qu'en mode complexe.");
            else
                throw CalculException("Syntaxe incorrecte.");
        }
    return 0;
}

Donnee* Factory::remake(std::string str)
{
    int i=0;
    std::string type,value;
    while(str[i]&&str[i]!=':')
        type+=str[i++];
    ++i;
    while(str[i])
        value+=str[i++];
    if(type=="Entier")
        return make_entier(value);
    if(type=="Rationnel")
        return make_rationnel(value);
    if(type=="Reel")
        return make_reel(value);
    if(type=="Complexe")
        return remake_complexe(value);
    if(type=="Expression")
        return remake_expression(value);
    if(type=="Operateur")
        return make_operateur(value);
    throw CalculException("Fichier corrompu.");
    return 0;
}
