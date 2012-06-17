#include "reel.h"

// Attention, constructeur de Rationnel à partir de Réel.
Rationnel::Rationnel(Reel r){

    num=r.getVal();
    denum=1;

    simplifier();
}


Reel::Reel(Entier e){

    val=(float)e.getVal();
}

Reel::Reel(Rationnel r){

    float Num=(float)r.getNumerateur().getVal();                    // Redondant le (float) ?
    float Denum=(float)r.getDenumerateur().getVal();

    val=Num/Denum;
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

Reel operator^( Reel& a,  Entier& b){              // POW a^b

    float val=a.getVal();
    for (int i=1;i<b.getVal();i++) val *= a.getVal();
    Entier res(val);
    return res;
}


/*
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

*/
