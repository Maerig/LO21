#include "operateur.h"

bool operateur_like(std::string str)
{
    int i=0;
    while(str[i])
    {
        if(number(str[i]))
            return false;
        ++i;
    }
    return true;
}


void Unifier(Donnee &A, Donnee &B){

    if ( (typeid(A).name()==Reel) || (typeid(B).name()==Reel) ) {

        A=Reel(float(A));
        B=Reel(float(B));

}
    else if ( (typeid(A).name()==Rationnel) || (typeid(B).name()==Rationnel) ){

        A=Rationnel(A);
        B=Rationnel(B);
}

}


    stack.empiler(new Rationnel(2,4));
    Donnee* data = stack.depiler();
    Reel x(24);Reel* px=&x;
    Rationnel* test = dynamic_cast<Rationnel*>(data);
    std::cerr<<test<<"\n";



*/


