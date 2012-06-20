/**
 * \file reel.cpp
 * \brief Developpement methodes class Reel et surcharge operateurs sur Reel
 *
 */

#include "reel.h"


Reel::Reel(Entier e){

    val=e.getVal();
}

Reel::Reel(Rationnel r){

    float Num=(float)r.getNumerateur().getVal();                    // Redondant le (float) ?
    float Denum=(float)r.getDenumerateur().getVal();

    val=Num/Denum;
}

Reel::Reel(Donnee *d){
    Reel* test1 = dynamic_cast< Reel*>(d);
    Rationnel* test2 = dynamic_cast< Rationnel*>(d);
    Entier* test3 = dynamic_cast< Entier*>(d);

    if (test1){
               val=test1->getVal();
              }
    else if (test2){
                val=float(*test2);
              }
    else if (test3){
               val=test3->getVal();
              }

    else throw CalculException("Erreur inattendue au niveau de la formation d'un reel par une donne. Cf reel.cpp");
}


Donnee* Reel::clone() const
{
    return new Reel(val);
}


Reel& Reel::operator=(const Reel& n)
{
    if(this != &n)
        val = n.val;
    return *this;
}


Reel operator+( Reel& a,  Reel& b){

    float val=a.getVal()+b.getVal();
    Reel res(val);
    return res;
}

Reel operator-( Reel& a,  Reel& b){
    float val=a.getVal()-b.getVal();
    Reel res(val);
    return res;
}

Reel operator*( Reel& a,  Reel& b){

    float val=a.getVal()*b.getVal();
    Reel res(val);
    return res;
}

Reel operator/( Reel& a,  Reel& b){

    float val=a.getVal()/b.getVal();
    Reel res(val);
    return res;
}








