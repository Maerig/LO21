#include "rationnel.h"
#include "reel.h"


/**
 * \brief Donne le pgcd de 2 nombres entiers naturels
 * Utilise dans la methode simplifier de rationnel
 */
double pgcd(unsigned long int a,unsigned long int b)
{
    int r =a%b;
    while(r!=0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

void Rationnel::simplifier(){

        if(num.getVal() != 0)
            {
                double p = pgcd(num.getVal(),denum.getVal());                 // Attention concordance type double et unsigned long int
                num.setVal(num.getVal()/p);
                denum.setVal(denum.getVal()/p);
                if (denum.getVal()<0 && num.getVal()<0 )                // si les 2 membres sont negatifs, la fraction devient positifs.
                {
                    num.setVal(-1*num.getVal());
                    denum.setVal(-1*denum.getVal());
                }
                if (denum.getVal() < 0)
                {
                    num.setVal(-1*num.getVal());
                    denum.setVal(-1*denum.getVal());
                }

            }
            else
                 denum.setVal(1);

}

Rationnel::Rationnel(Donnee *d){
    Reel* test1 = dynamic_cast< Reel*>(d);
    Rationnel* test2 = dynamic_cast< Rationnel*>(d);
    Entier* test3 = dynamic_cast< Entier*>(d);

        if (test1){
            throw CalculException("Erreur inattendue au niveau de la formation d'un Complexe par une donnee: Reel donne pour former un complexe.\nCf reel.cpp");
                  }
       if (test2){
                    num=test2->getNumerateur();
                    denum=test2->getDenumerateur();
                  }
        else if (test3){
                   num=test3->getVal();
                   Entier* A=new Entier(1);
                   denum=*A;
                  }

        else throw CalculException("Erreur inattendue au niveau de la formation d'un Complexe par une donnee. Cf reel.cpp");

        this->simplifier();
}

Donnee* Rationnel::clone() const
{
    return new Rationnel(num,denum);
}

Rationnel& Rationnel::operator=(const Rationnel& n){
    if(this != &n){
        num= n.num;
        denum= n.denum;
    }
    return *this;
}


Rationnel operator+( Rationnel& a,  Rationnel& b){


    Entier valDenum( a.getDenumerateur().getVal() * b.getDenumerateur().getVal());
    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() + b.getNumerateur().getVal()*a.getDenumerateur().getVal() );

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator-( Rationnel& a,  Rationnel& b){
    Entier valDenum( a.getDenumerateur().getVal() * b.getDenumerateur().getVal());
    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() - b.getNumerateur().getVal()*a.getDenumerateur().getVal() );

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator*( Rationnel& a,  Rationnel& b){

    Entier valNum( a.getNumerateur().getVal()*b.getNumerateur().getVal() );
    Entier valDenum( a.getDenumerateur().getVal()*b.getDenumerateur().getVal() );

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator/( Rationnel& a,  Rationnel& b){

    Entier valNum( a.getNumerateur().getVal()*b.getDenumerateur().getVal() );
    Entier valDenum( a.getDenumerateur().getVal()*b.getNumerateur().getVal() );

    Rationnel res(valNum, valDenum);
    return res;
}










