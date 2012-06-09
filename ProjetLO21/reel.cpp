#include "reel.h"

Reel::Reel(Entier e){

    val=(float)e.getVal();
}

Reel::Reel(Rationnel r){

    float Num=r.getNumerateur();
    float Denum=r.getDenumerateur();

    val=Num/Denum;
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
