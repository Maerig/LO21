#include "entier.h"

Entier operator+( Entier& a,  Entier& b){

    double val=a.getVal()+b.getVal();
    Entier res(val);
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

    double val=a.getVal()/b.getVal();
    Entier res(val);
    return res;
}

Entier operator%( Entier& a,  Entier& b){
    double val=(int)a.getVal()%(int)b.getVal();
    Entier res(val);
    return res;
}

Entier operator^( Entier& a,  Entier& b){               // POW a^b

    double val=a.getVal();
    for (int i=1;i<b.getVal();i++)
        val*=a.getVal();
    Entier res(val);
    return res;
}

