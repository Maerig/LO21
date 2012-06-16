#include "operateurunaire.h"

#include <math.h>


double factoriel (double d);


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
    if (typeangles==degre) *C=Reel(sin(A.getVal()/180*M_PI));           // problème affichage
    else *C=Reel(sin(A.getVal()));

    stack->empiler(C);

}


void Cosinus::Calculer(Pile *stack){
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
    if (typeangles==degre) *C=Reel(cos(A.getVal()/180*M_PI));
    else *C=Reel(cos(A.getVal()));

   stack->empiler(C);
}


void Tang::Calculer(Pile *stack){
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
    if (typeangles==degre) *C=Reel(tan(A.getVal()/180*M_PI));
    else *C=Reel(tan(A.getVal()));
    stack->empiler(C);


}


void Sinush::Calculer(Pile *stack){
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
    if (typeangles==degre) *C=Reel(sinh(A.getVal()/180*M_PI));
    else *C=Reel(sinh(A.getVal()));
    stack->empiler(C);

}


void Cosinush::Calculer(Pile *stack){
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
    if (typeangles==degre) *C=Reel(cosh(A.getVal()/180*M_PI));
    else *C=Reel(cosh(A.getVal()));
    stack->empiler(C);


}


void Tangh::Calculer(Pile *stack){
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
    if (typeangles==degre) *C=Reel(tanh(A.getVal()/180*M_PI));
    else *C=Reel(tanh(A.getVal()));
    stack->empiler(C);
}


void Sqrt::Calculer(Pile *stack){
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
    *C=Reel(sqrt(A.getVal()));
    stack->empiler(C);

}


void Sqr::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(pow(A.getVal(),2));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0,1);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel(pow(A.getNumerateur(),2),pow(A.getDenumerateur(),2));
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Entier* C = new Entier;
                    *C=Entier(pow(A.getVal(),2));
                    stack->empiler(C);
                  }


}


void Ln::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(log(A.getVal()));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel((unsigned long int)log(A.getNumerateur()/A.getDenumerateur())*100000000,100000000);
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Entier* C = new Entier;
                    *C=Entier((unsigned long int)log(A.getVal()));
                    stack->empiler(C);
                  }


}


void Log::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(log10(A.getVal()));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel((unsigned long int)log10(A.getNumerateur()/A.getDenumerateur()),1);
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Entier* C = new Entier;
                    *C=Entier((unsigned long int)log10(A.getVal()));
                    stack->empiler(C);
                  }


}


void Cube::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(pow(A.getVal(),3));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0,1);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel(pow(A.getNumerateur(),3),pow(A.getDenumerateur(),3));
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Entier* C = new Entier;
                    *C=Entier(pow(A.getVal(),3));
                    stack->empiler(C);
                  }

}


void Fact::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Entier* test3 = dynamic_cast< Entier*>(dA);

    Reel* test1 = dynamic_cast< Reel*>(dA);                     // Mettre en place erreur pour ces 2
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);


    if (test3) {
                Entier A(0);
                A=Entier(*test3);
                Entier* C = new Entier;
                //*C=Entier(5);
                *C=Entier(factoriel(A.getVal()));
                stack->empiler(C);
              }
    else stack->empiler(dA);


}


void Sign::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(0-A.getVal());
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0,1);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel(0-A.getNumerateur().getVal(),A.getDenumerateur().getVal());
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Entier* C = new Entier;
                    *C=Entier(0-A.getVal());
                    stack->empiler(C);
                  }

}


void Inv::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);


    if (test1){
                Reel A(0);
                A=Reel(*test1);
                Reel* C = new Reel;
                *C=Reel(1/A.getVal());
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A(0,1);
                    A=Rationnel(*test2);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel(A.getDenumerateur(),A.getNumerateur());
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A(0);
                    A=Entier(*test3);
                    Rationnel* C = new Rationnel;
                    *C=Rationnel(1,A.getVal());
                    stack->empiler(C);
                  }

}





double factoriel (double d){
    if (d==1) return 1;
    return d*factoriel(d-1);
}
