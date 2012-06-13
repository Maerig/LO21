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


void Unifier(Donnee *A, Donnee *B){

    const Reel* test1 = dynamic_cast<const Reel*>(A);
    const Reel* test2 = dynamic_cast<const Reel*>(B);
    const Rationnel* test3 = dynamic_cast<const Rationnel*>(A);
    const Rationnel* test4 = dynamic_cast<const Rationnel*>(B);

    if ( test1 || test2 ) {

        *A=Reel(float(*A));
        *B=Reel(float(*B));

}
    else if ( test3 || test4){

        *A=Rationnel(*A);
        *B=Rationnel(*B);
}

}

/*
    stack.empiler(new Rationnel(2,4));
    Donnee* data = stack.depiler();

    Rationnel* test = dynamic_cast<Rationnel*>(data);
    std::cerr<<test<<"\n";

    if ( (typeid(A).name()==Reel) || (typeid(B).name()==Reel) ) {

        A=Reel(float(A));
        B=Reel(float(B));

}
    else if ( (typeid(A).name()==Rationnel) || (typeid(B).name()==Rationnel) ){

        A=Rationnel(A);
        B=Rationnel(B);
}
*/


*/


