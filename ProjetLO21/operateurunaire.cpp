#include "operateurunaire.h"

#include <math.h>





void Sinus::Calculer(Pile *stack){

    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Reel A(0);

    if (test1){
                A=Reel(*test1);
              }
    else if(test2){
                    A=Rationnel(*test2);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    Reel* C = new Reel;
    *C=Reel(sin(A.getVal()));
    stack->empiler(C);

}


void Cosinus::Calculer(Pile *stack){


}


void Tang::Calculer(Pile *stack){


}


void Sinush::Calculer(Pile *stack){


}


void Cosinush::Calculer(Pile *stack){


}


void Tangh::Calculer(Pile *stack){


}


void Sqrt::Calculer(Pile *stack){


}


void Sqr::Calculer(Pile *stack){


}


void Ln::Calculer(Pile *stack){


}


void Log::Calculer(Pile *stack){


}


void Inv::Calculer(Pile *stack){


}


void Cube::Calculer(Pile *stack){


}

void Fact::Calculer(Pile *stack){



}
