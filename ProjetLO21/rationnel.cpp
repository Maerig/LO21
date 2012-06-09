#include "rationnel.h"

double pgcd(unsigned long int a,unsigned long int b)
{
    unsigned long int r =a%b;
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

        if(num   != 0)
            {
                double p = pgcd(num,denum);                 // Attention concordance type double et unsigned long int
                num/=p;
                denum /= p;
                if (num < 0)
                {
                    num *= -1;
                    denum *= -1;
                }
            }
            else
                 denum=1;

}



Rationnel operator+( Rationnel& a,  Rationnel& b){


    double valDenum= ppcm(a.getNumerateur(),b.getNumerateur());
    double valNum=(a.getNumerateur()*valDenum)+(b.getNumerateur()*valDenum);

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator-( Rationnel& a,  Rationnel& b){
    double valDenum= ppcm(a.getNumerateur(),b.getNumerateur());
    double valNum=(a.getNumerateur()*valDenum)-(b.getNumerateur()*valDenum);

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator*( Rationnel& a,  Rationnel& b){

    double valNum=a.getNumerateur()*b.getNumerateur();
    double valDenum=a.getDenumerateur()*b.getDenumerateur();

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator/( Rationnel& a,  Rationnel& b){

    double valNum=a.getNumerateur()*b.getDenumerateur();
    double valDenum=a.getDenumerateur()*b.getNumerateur();

    Rationnel res(valNum, valDenum);
    return res;
}

Rationnel operator^( Rationnel& a,  Entier& b){                     // POW a^b

    double num=a.getNumerateur();
    double denum=a.getDenumerateur();

    for (int i=1;i<b.getVal();i++)
        num*=a.getNumerateur();
        denum*=a.getNumerateur();

    Rationnel res(num,denum);
    return res;
}

