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


int Unifier(Donnee *A, Donnee *B){

    const Reel* test1 = dynamic_cast<const Reel*>(A);
    const Reel* test2 = dynamic_cast<const Reel*>(B);
    const Rationnel* test3 = dynamic_cast<const Rationnel*>(A);
    const Rationnel* test4 = dynamic_cast<const Rationnel*>(B);

    if ( *test1 || *test2 ) {

        *A=Reel(float(*test1));
        *B=Reel(float(*test2));
        return 2;
    }

    else if ( *test3 || *test4){

        *A=Rationnel(*test3);
        *B=Rationnel(*test4);
        return 1;
    }

    return 0;
}
