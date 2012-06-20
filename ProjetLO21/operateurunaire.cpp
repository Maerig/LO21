/**
 * \file operateurunaire.cpp
 * \brief fonctions calculer des operateurs unaires.
 *
 * Les operateurs + - * / surcharges avec les classes Entier, Reel, Rationnel et complexe sont utilises pour le calcul des operations unaires.
 * La bibliotheque math.h est egalement largement utilise.
 */

#include "operateurunaire.h"
#include <math.h>

/* Fonction factoriel recursive, utilisee dans le calcul du factoriel d'une donnee.*/
/*!
 * \brief calcul recursif du factoriel d'un nombre double
 *
 */
double factoriel (unsigned long int d);


/*!
 * \brief Operation unaire Sinus. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Sinus::Calculer(Pile *stack){

    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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
        if (typeangles==degre) *C=Reel(sin(A.getVal()/180*M_PI));
        else *C=Reel(sin(A.getVal()));

        stack->empiler(C);
    }
}

/*!
 * \brief Operation unaire Cosinus. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Cosinus::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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
    if (typeangles==degre) {    if (!(A.getVal()==90 || A.getVal()==-90))           // Condition pour permettre l'affichage de zero si les valeurs remarquables 90 et -90 sont entrees.
                               *C=Reel(cos(A.getVal()/180*M_PI));
                           }
    else *C=Reel(cos(A.getVal()));

    stack->empiler(C);
    }
}

/*!
 * \brief Operation unaire Tang. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Tang::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operation unaire SinusH. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Sinush::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operations unaire CosinusH. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Cosinush::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operations unaire TangH. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour les operateurs de calcul trigonometrique, comme ici, le resultat est de type reel, donc on ramene toute les donnees au type reel. Les complexes ne sont pas acceptes.
 */
void Tangh::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operations unaire Sqrt racine carre. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation SQRT, le resultat est de type reel, puisque dans la majorite des cas la racine carre n'est pas un entier, donc on ramene toute les donnees au type reel.
 * Les complexes ne sont pas acceptes.
 */
void Sqrt::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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
    // Pour l'operateur racine carre, on ramene toute les donnees au type reel.
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

/*!
 * \brief Operations unaire Sqr (ou carre d'un nombre). Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation SQRT, tous les types de donneee sont acceptees.
 */
void Sqr::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operations unaire Ln. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Attention au cas ou le nombre donne est egal ou inferieur a zero.
 * Pour l'operation Ln, on a fait le choix de maintenir le resultat dans le type de la donnee calcule, au prix d'un risque de perte des informations. Les complexes ne sont pas acceptes.
 */
void Ln::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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
                    if (A.getVal()>0){  Reel* C = new Reel(log(A.getVal())); stack->empiler(C); }
                    else {
                        stack->empiler(dA);
                        throw CalculException("On ne peut calculer le LN d'un nombre negatif.");
                    }
                  }
        else if(test2){
                        Rationnel A=Rationnel(dA);
                        if (A.getNumerateur().getVal()>0) {
                            Rationnel* C = new Rationnel(log(A.getNumerateur()/A.getDenumerateur()));
                            stack->empiler(C);
                        }
                        else {
                            stack->empiler(dA);
                            throw CalculException("On ne peut calculer le LN d'un nombre negatif.");
                        }
                      }
        else if(test3){
                        Entier A=Entier(*test3);
                        if (A.getVal()==0){
                            Entier* C = new Entier((unsigned long int)log(A.getVal()));
                            stack->empiler(C);
                        }
                        else {
                            stack->empiler(dA);
                            throw CalculException("On ne peut calculer le LN d'un nombre negatif.");
                        }
                      }

        else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n LN - Operateurunaire.cpp");
    }
}


/*!
 * \brief Operations unaire Log. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation Log, on a fait le choix de maintenir le resultat dans le type de la donnee calcule, au prix d'une perte des informations. Les complexes ne sont pas acceptes.
 */
void Log::Calculer(Pile *stack){

    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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
                    if (A.getVal()){
                            Reel* C = new Reel(log10(A.getVal()));
                            stack->empiler(C);
                    }
                    else {
                        stack->empiler(dA);
                        throw CalculException("On ne peut calculer le LOG d'un nombre negatif.");
                    }
                  }
        else if(test2){
                        Rationnel A=Rationnel(dA);
                        if (A.getNumerateur().getVal()==0){
                                Rationnel* C = new Rationnel(log10(A.getNumerateur()/A.getDenumerateur()));
                                stack->empiler(C);
                              }
                        else {
                            stack->empiler(dA);
                            throw CalculException("On ne peut calculer le LOG d'un nombre negatif.");
                        }
                  }
        else if(test3){
                        Entier A=Entier(*test3);
                        if (A.getVal()==0){
                                Entier* C = new Entier(log10(A.getVal()));
                                stack->empiler(C);
                        }
                        else {
                            stack->empiler(dA);
                            throw CalculException("On ne peut calculer le LOG d'un nombre negatif.");
                        }
                      }

        else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\n Log - Operateurunaire.cpp");
    }
}


/*!
 * \brief Operations unaire Cube. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation Cube, tous les types de donneee sont acceptees. */
void Cube::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operations unaire Factoriel. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation Factoriel, uniquement le type donnee est accepte.
 */
void Fact::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operation unaire inversement du signe ou oppose. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation SIGN, tous les types sont acceptes. La methode setSign() est utilise ici pour inverser le signe des donnees.
 */
void Sign::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
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

/*!
 * \brief Operation unaire INV ou l'inverse. Fonction virtuelle herite d'operateur.
 *
 * La fonction calculer est structurellement identique pour toute les operations unaires.
 * D'abord, la premiere donnee de la pile est depile.
 * Verification si ce n'est pas une expression, auquel cas on enfilerai l'operateur a la fin de l'expression et on empilerai l'expression a nouveau dans la pile.
 * Si la donnees depilee est d'un type non acceptable pour l'operation, la donnee est re-empilee, et une exception est envoyee.
 * La donnee resultat est sinon empilee.
 * Pour l'operation INV, tous les types à l'exception de complexe sont acceptes. Les entiers deviennent des rationnels.
 */
void Inv::Calculer(Pile *stack){
    Donnee* dA= stack->depiler();
    Expression* testEx =dynamic_cast<Expression*>(dA);

    if (testEx) {
        testEx->enfiler_fin(this);                           // Si la donnee est une expression, il faut enfiler l'operateur a la fin de l'expression.
        stack->empiler(testEx);
    }

    else {
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Rationnel* test2 = dynamic_cast< Rationnel*>(dA);
    Entier* test3 = dynamic_cast< Entier*>(dA);
    Complexe* test4 = dynamic_cast< Complexe*>(dA);

    if (test4) {
                stack->empiler(dA);
                throw CalculException("Fonction INV non disponible pour complexe.");
               }

    if (test1){
                Reel A=Reel(dA);
                if (A.getVal()==0) {
                            Reel* C = new Reel(1/A.getVal());
                            stack->empiler(C);
                }
                else {
                    stack->empiler(dA);
                    throw CalculException("Inverse de zero impossible.");
                }
              }
    else if(test2){
                    Rationnel A=Rationnel(dA);
                    if (A.getNumerateur().getVal()){
                            Rationnel* C = new Rationnel(A.getDenumerateur(),A.getNumerateur());
                            stack->empiler(C);
                    }
                    else {
                        stack->empiler(dA);
                        throw CalculException("Inverse de zero impossible.");
                    }
                  }
    else if(test3){                                                     // Les nombres du type entier deviennent des rationnels. (Absurde sinon)
                    Entier A=Entier(*test3);
                    if (A.getVal()){
                            Rationnel* C = new Rationnel(1,A.getVal());
                            stack->empiler(C);
                    }
                    else {
                        stack->empiler(dA);
                        throw CalculException("Inverse de zero impossible.");
                    }
                  }
    else throw CalculException("Probleme imprevu, erreur reconnaissance donne.\nINV - Operateurunaire.cpp");
    }
}





double factoriel (unsigned long int d){
    if (d==0) return 1;
    return d*factoriel(d-1);
}
