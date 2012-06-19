#include "operateurunaire.h"

#include <math.h>

/* Fonction factoriel recursive, utilisée dans le calcul du factoriel d'une donnee.*/
/*!
 * \brief calcul recursif du factoriel d'un nombre double
 *
 */
double factoriel (double d);


/*!
 * \brief Operations + - * / Modulo et Puissance
 *
 * La fonction calculer est la meme pour tout les operateurs binaires, mettant ainsi en commun le processus d'identification des données.
 * Au sein de la fonction Calculer, un switch sur typeOperateur permet d'adapter le calcul au cas désiré.
 * La donnée resultat est ensuite re-empilée.
 * Si les données dépilées sont d'un type non acceptable pour l'operation, les données sont re-empilées dans le bon ordre, et une exception est envoyée.
 * La donnée résultat est sinon empilée.
 * Dans le cas d'une donnée dépilée étant du type expressions, l'autre donnée et l'operateur sont enfiler au début ou à la fin de l'expression, selon les cas.
 */
void Sinus::Calculer(Pile *stack){

    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
        Reel* test1 = dynamic_cast< Reel*>(dA);
        Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
        Entier* test3 = dynamic_cast< Entier*>(dA);
        Complexe* test4 = dynamic_cast< Complexe*>(dA);

        if (test4) {
                    stack->empiler(dA);
                    throw CalculException("Fonction Sinus non disponible pour complexe.");
                   }

        Reel A;
        // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
        if (test1){
                    A=Reel(dA);
                  }
        else if(test2){
                        A=Rationnel(dA);
                      }
        else if(test3){
                        A=Entier(*test3);
                      }
        else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n SINUS - Operateurunaire.cpp");
        Reel* C = new Reel;
        if (typeangles==degre) *C=Reel(sin(A.getVal()/180*M_PI));           // problème affichage
        else *C=Reel(sin(A.getVal()));

        stack->empiler(C);
    }
}


void Cosinus::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction Cosinus non disponible pour complexe.");
               }

    Reel A;
    // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n COSINUS - Operateurunaire.cpp");

    Reel* C = new Reel;
    if (typeangles==degre) {    if (!(A.getVal()==90 || A.getVal()==-90))           // Condition pour permettre l'affichage de zero si les valeurs remarquables 90 et -90 sont entrées.
                               *C=Reel(cos(A.getVal()/180*M_PI));
                           }
    else *C=Reel(cos(A.getVal()));

    stack->empiler(C);
    }
}


void Tang::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction Tan non disponible pour complexe.");
               }
    Reel A;
    // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n TANG - Operateurunaire.cpp");
    Reel* C = new Reel;
    if (typeangles==degre) *C=Reel(tan(A.getVal()/180*M_PI));
    else *C=Reel(tan(A.getVal()));
    stack->empiler(C);
    }
}


void Sinush::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction SinusH non disponible pour complexe.");
               }
    Reel A;
    // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n SINUSH - Operateurunaire.cpp");
    Reel* C = new Reel;
    if (typeangles==degre) *C=Reel(sinh(A.getVal()/180*M_PI));
    else *C=Reel(sinh(A.getVal()));
    stack->empiler(C);
    }
}


void Cosinush::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction CosinusH non disponible pour complexe.");
               }
    Reel A;
    // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n COSINUSH - Operateurunaire.cpp");
    Reel* C = new Reel;
    if (typeangles==degre) *C=Reel(cosh(A.getVal()/180*M_PI));
    else *C=Reel(cosh(A.getVal()));
    stack->empiler(C);
    }
}


void Tangh::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction TanH non disponible pour complexe.");
               }
    Reel A;
    // Pour les operateurs de calcul trigonometrique, on ramene toute les donnees au type reel.
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n TANGH - Operateurunaire.cpp");
    Reel* C = new Reel;
    if (typeangles==degre) *C=Reel(tanh(A.getVal()/180*M_PI));
    else *C=Reel(tanh(A.getVal()));
    stack->empiler(C);
   }
}


void Sqrt::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction Sqrt non disponible pour complexe.");
               }
    Reel A;
    // Pour l'operateur racine carre, on ramene toute les donnees au type reel.(Puisque dans la majorité des cas la racine carre n'est pas un entier)
    if (test1){
                A=Reel(dA);
              }
    else if(test2){
                    A=Rationnel(dA);
                  }
    else if(test3){
                    A=Entier(*test3);
                  }

    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n SQRT - Operateurunaire.cpp");

    Reel* C = new Reel;
    *C=Reel(sqrt(A.getVal()));
    stack->empiler(C);
    }
}


void Sqr::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    // Tous les types de donnees numeriques acceptent l'operation "au carre"

    if (test1){
                Reel A=Reel(dA);
                Reel* C = new Reel(pow(A.getVal(),2));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A=Rationnel(dA);
                    Rationnel* C = new Rationnel(pow(A.getNumerateur(),2),pow(A.getDenumerateur(),2));
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A=Entier(*test3);
                    Entier* C = new Entier(pow(A.getVal(),2));
                    stack->empiler(C);
                  }
    else if (test4) {
                    Complexe A=Complexe(*test4);
                    Complexe* C = new Complexe(A*A);
                    stack->empiler(C);
                    }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n SQR - Operateurunaire.cpp");
    }
}


void Ln::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
        Reel* test1 = dynamic_cast< Reel*>(dA);
        Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
        Entier* test3 = dynamic_cast< Entier*>(dA);
        Complexe* test4 = dynamic_cast< Complexe*>(dA);

        if (test4) {
                    stack->empiler(dA);
                    throw CalculException("Fonction Ln non disponible pour complexe.");
                   }

        // Le resultat est maintenu dans le type de la donnee calcule, au prix d'une perte des informations.
        else if (test1){
                    Reel A=Reel(dA);
                    Reel* C = new Reel(log(A.getVal()));
                    stack->empiler(C);
                  }
        else if(test2){
                        Rationnel A=Rationnel(dA);
                        Rationnel* C = new Rationnel(log(A.getNumerateur()/A.getDenumerateur()));
                        stack->empiler(C);
                      }
        else if(test3){
                        Entier A=Entier(*test3);
                        Entier* C = new Entier((unsigned long int)log(A.getVal()));
                        stack->empiler(C);
                      }

        else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n LN - Operateurunaire.cpp");
    }
}

void Log::Calculer(Pile *stack){

    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
        Reel* test1 = dynamic_cast< Reel*>(dA);
        Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
        Entier* test3 = dynamic_cast< Entier*>(dA);
        Complexe* test4 = dynamic_cast< Complexe*>(dA);

        if (test4) {
                    stack->empiler(dA);
                    throw CalculException("Fonction Log non disponible pour complexe.");
                   }

        // Le resultat est maintenu dans le type de la donnee calcule, au prix d'une perte des informations.
        else if (test1){
                    Reel A=Reel(dA);
                    Reel* C = new Reel;
                    *C=Reel(log10(A.getVal()));
                    stack->empiler(C);
                  }
        else if(test2){
                        Rationnel A=Rationnel(dA);
                        Rationnel* C = new Rationnel(log10(A.getNumerateur()/A.getDenumerateur()));
                        stack->empiler(C);
                      }
        else if(test3){
                        Entier A=Entier(*test3);
                        Entier* C = new Entier(log10(A.getVal()));
                        stack->empiler(C);
                      }

        else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n Log - Operateurunaire.cpp");
    }
}


void Cube::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

     // Tous les types de donnees numeriques acceptent l'operation cube.
    if (test1){
                Reel A=Reel(dA);
                Reel* C = new Reel(pow(A.getVal(),3));
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A=Rationnel(dA);
                    Rationnel* C = new Rationnel(pow(A.getNumerateur(),3),pow(A.getDenumerateur(),3));
                    stack->empiler(C);
                  }
    else if(test3){
                    Entier A=Entier(*test3);
                    Entier* C = new Entier(pow(A.getVal(),3));
                    stack->empiler(C);
                  }
    else if (test4) {
                    Complexe A=Complexe(*test4);
                    Complexe* C = new Complexe(A*A*A);
                    stack->empiler(C);
               }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n CUBE - Operateurunaire.cpp");
    }
}


void Fact::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Entier* test3 = dynamic_cast< Entier*>(dA);

    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);


    if (test3) {
                Entier A=Entier(*test3);
                Entier* C = new Entier(factoriel(A.getVal()));
                stack->empiler(C);
              }
    else {
            stack->empiler(dA);
            if (test2) throw CalculException("Impossible de calculer factoriel d'un rationnel.\nFonction utilisable avec Entier uniquement.");
            else if (test4) throw CalculException("Impossible de calculer factoriel d'un Complexe.\nFonction utilisable avec Entier uniquement.");
            else if (test1) throw CalculException("Impossible de calculer factoriel d'un reel.\nFonction utilisable avec Entier uniquement.");
            else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n FACT - Operateurunaire.cpp");
        }

    }
}


void Sign::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);


    if (test1){
                Reel* A=new Reel(dA);
                A->setSign();
                stack->empiler(A);
              }
    else if(test2){
                    Rationnel* A=new Rationnel(dA);
                    A->setSign();
                    stack->empiler(A);
                  }
    else if(test3){
                    Entier* A=new Entier(*test3);
                    A->setSign();
                    stack->empiler(A);
                  }
    else if(test4){
                    Complexe* A=new Complexe(dA);
                    A->setSign();
                    stack->empiler(A);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\nSIGN - Operateurunaire.cpp");
    }
}


void Inv::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnée est une expression, il faut enfiler l'operateur à la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction Log non disponible pour complexe.");
               }

    if (test1){
                Reel A=Reel(dA);
                Reel* C = new Reel(1/A.getVal());
                stack->empiler(C);
              }
    else if(test2){
                    Rationnel A=Rationnel(dA);
                    Rationnel* C = new Rationnel(A.getDenumerateur(),A.getNumerateur());
                    stack->empiler(C);
                  }
    else if(test3){                                                     // Les nombres du type entier deviennent des rationnels. (Absurde sinon)
                    Entier A=Entier(*test3);
                    Rationnel* C = new Rationnel(1,A.getVal());
                    stack->empiler(C);
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\nINV - Operateurunaire.cpp");
    }
}





double factoriel (double d){
    if (d==1) return 1;
    return d*factoriel(d-1);
}
