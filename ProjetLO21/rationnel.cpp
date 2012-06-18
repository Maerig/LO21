#include "rationnel.h"
#include "reel.h"

Rationnel::Rationnel(Reel r){

    num=r.getVal();
    denum=1;

    simplifier();
}


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

double ppcm(double a, double b)
{
    double x=a, y=b;
    while(x!=y)
    {
        if(x<y)
            x+=a;
        else
            y+=b;
    }
    return x;
}

void Rationnel::simplifier(){

        if(num.getVal() != 0)
            {
                double p = pgcd(num.getVal(),denum.getVal());                 // Attention concordance type double et unsigned long int
                num.setVal(num.getVal()/p);
                denum.setVal(denum.getVal()/p);
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

Rationnel operator^( Rationnel& a,  Entier& b){                     // POW a^b

    Entier num(a.getNumerateur().getVal());
    Entier denum(a.getDenumerateur().getVal());

    for (int i=1;i<b.getVal();i++)
        num.setVal( num.getVal()*a.getNumerateur().getVal() );
        denum.setVal( denum.getVal()*a.getDenumerateur().getVal() );

    Rationnel res(num,denum);
    return res;
}








