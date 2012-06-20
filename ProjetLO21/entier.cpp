/**
 * \file entier.cpp
 * \brief Developpement methodes class Entier et surcharge operateurs sur Entiers
 *
 */

#include "entier.h"

Donnee* Entier::clone() const
{
    return new Entier(val);
}

Entier& Entier::operator=(const Entier& n)
{
    if(this != &n)
        val = n.val;
    return *this;
}

Entier operator+(Entier& a,  Entier& b){

    double valeur=a.getVal()+b.getVal();
    Entier res(valeur);
    return res;
}

Entier operator-( Entier& a,  Entier& b){

    double val=a.getVal()-b.getVal();
    Entier res(val);
    return res;
}

Entier operator*( Entier& a,  Entier& b){

    double val=a.getVal()*b.getVal();
    Entier res(val);
    return res;
}

Entier operator/( Entier& a,  Entier& b){

    unsigned int val=a.getVal()/b.getVal();
    Entier res(val);
    return res;
}

Entier operator%( Entier& a,  Entier& b){
    double val=(int)a.getVal()%(int)b.getVal();
    Entier res(val);
    return res;
}


