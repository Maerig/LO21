/**
 * \file operateurbinaire.cpp
 * \brief Methodes objet OperateurBinaire. Calcul avec operateurs binaire.
 *
 * Affichage des Operateurs Binaires. Fonction clone.
 * Les operateurs + - * / surcharges avec les classes Entier, Reel, Rationnel et complexe sont utilises pour le calcul des operations unaires.
 * La bibliotheque math.h est egalement largement utilise.
 */



#include "operateurbinaire.h"
#include "calculexception.h"

#include <iostream>
#include <math.h>

/*! \fn OperateurBinaire::Calculer
 * \brief Fonction virtuelle herite d'operateur. Operations + - * / Modulo et Puissance
 *
 * La fonction calculer est la meme pour tout les operateurs binaires, mettant ainsi en commun le processus de dépilement et d'identification des données.
 * Au sein de la fonction Calculer, un switch sur typeOperateur permet d'adapter le calcul au cas désiré.
 *
 * Les operateurs + - * / surcharges avec les classes Entier, Reel, Rationnel et complexe sont utilises pour le calcul des operations unaires.
 * La bibliotheque math.h est egalement largement utilise.
 *
 * Si les données dépilées sont d'un type non acceptable pour l'operation, les données sont re-empilées dans le bon ordre, et une exception est envoyée.
 * La donnée résultat est sinon empilée.
 * Dans le cas d'une donnée dépilée étant du type expressions, l'autre donnée et l'operateur sont enfiler au début ou à la fin de l'expression, selon les cas.
 */
void OperateurBinaire::Calculer(Pile* stack){

    Donnee* dB= stack->depiler();                           // On commence par depiler les 2 dernieres donnees entrees. B est la derniere donne empile, donc le second membre de l'operation. La seconde donne empile est le premier membre, A.
    Donnee* dA= stack->depiler();

    Expression* testExA =dynamic_cast<Expression*>(dA);     // On verifie d'abord si l'une des 2 donnees n'est pas une expression. Il faudra alors cancatener l'expression avec l'autre donnee et l'operateur.
    Expression* testExB =dynamic_cast<Expression*>(dB);

    if (testExA) {
        testExA->enfiler_fin(dB);
        testExA->enfiler_fin(this);                           // Si le premier membre est une expression, il faut enfiler le second membre et l'operateur à la fin successivement.
        stack->empiler(testExA);
    }

    else if (testExB) {
           testExB->enfiler_debut(dA);
           testExB->enfiler_fin(this);                          // Si le second membre est une expression et que le premier ne l'est pas, il faut enfiler le premier membre au début de B, et l'operateur à la fin.
           stack->empiler(testExB);
         }
    else {

    Complexe* testC1 = dynamic_cast< Complexe*>(dA);
    Complexe* testC2 = dynamic_cast< Complexe*>(dB);
    Reel* test1 = dynamic_cast< Reel*>(dA);
    Reel* test2 = dynamic_cast< Reel*>(dB);
    Rationnel* test3 = dynamic_cast< Rationnel*>(dA);
    Rationnel* test4 = dynamic_cast< Rationnel*>(dB);
    Entier* testE1 = dynamic_cast< Entier*>(dA);
    Entier* testE2 = dynamic_cast< Entier*>(dB);


    if ( testC1 || testC2){                 //On a au moins un complexe. On travaille donc avec des complexes.

        Complexe A= Complexe(dA);           // constructeur de complexe a partir de donnee.
        Complexe B= Complexe(dB);

            switch (typeoperation) {        // Switch selon le type de l'operation, attribut de l'operateurBinaire.

                case (PLUS):
                {
                    Complexe *X= new Complexe(A+B);
                    stack->empiler(X);
                }

                    break;

                case(MINUS):
                {
                    Complexe *X= new Complexe(A-B);
                    stack->empiler(X);
                }
                    break;


                case(DIV):
                {
                    Complexe *X= new Complexe(A/B);
                    stack->empiler(X);
                }
                    break;

                case (MULT):
                {
                    Complexe *X= new Complexe(A*B);
                    stack->empiler(X);
                }
                    break;

                case(MODULO):
                {
                    stack->empiler(dA);                         // Modulo inappliquable sur complexes. On re-empile donc les donnees dans le bon ordre.
                    stack->empiler(dB);
                    throw CalculException("Modulo inappliquable pour Complexe.\nFonction utilisable avec Entier uniquement.");
                }
                    break;

                case (POW):
                {
                    stack->empiler(dA);
                    stack->empiler(dB);
                    throw CalculException("POW inappliquable pour Complexe.");
                }

                    break;

            }
    }

    else if ( test1 || test2 ) {     //Au moins un reel

        Reel A=Reel(dA);
        Reel B=Reel(dB);

        Reel* dC = new Reel;

        switch (typeoperation) {
            case (PLUS):
                        {
                                    *dC=(A+B);
                                    stack->empiler(dC);
                        }
                break;

            case(MINUS):
                        {
                                    *dC=(A-B);
                                    stack->empiler(dC);
                        }

                break;

            case(DIV):
                        {

                            if (B.getVal()==0){                                         //Cas ou une division par zero est tentée.
                                                stack->empiler(dA);
                                                stack->empiler(dB);
                                                throw CalculException("Division par zero impossible.");
                                            }

                            else {
                                *dC=(A/B);
                                stack->empiler(dC);
                                }
                        }

                break;

            case (MULT):
                        {
                                    *dC=(A*B);
                                    stack->empiler(dC);
                        }

                break;

            case(MODULO):
        {
            stack->empiler(dA);
            stack->empiler(dB);
            throw CalculException("Modulo inappliquable pour Reel.\nFonction utilisable avec Entier uniquement.");
        }

                break;

            case (POW):
        {
                    *dC=(A*B);
                    *dC=Reel(pow(A.getVal(),B.getVal()));
                    stack->empiler(dC);
        }

                break;

        }
    }

    else if ( test3 || test4 ) {        //Au moins un rationnel

        Rationnel A=Rationnel(dA);
        Rationnel B=Rationnel(dB);

        Rationnel* dC = new Rationnel;

            switch (typeoperation) {
            case (PLUS):
                       {

                            *dC=(A+B);
                            stack->empiler(dC);
                       }
                break;
            case(MINUS):
                        {
                             *dC=(A-B);
                             stack->empiler(dC);
                        }

                break;

            case(DIV):
                        {

                             if (B.getNumerateur().getVal()==0){
                                                 stack->empiler(dA);
                                                 stack->empiler(dB);
                                                 throw CalculException("Division par zero impossible.");
                                             }

                             else {
                                 *dC=(A/B);
                                 stack->empiler(dC);
                                 }
                        }

                break;

            case (MULT):
                        {
                             *dC=(A*B);
                             stack->empiler(dC);
                        }

                break;

            case(MODULO):
                        {
                            stack->empiler(dA);
                            stack->empiler(dB);
                            throw CalculException("Modulo inappliquable pour Rationnel.\nFonction utilisable avec Entier uniquement.");
                        }
                break;

            case (POW):
                        {
                             *dC=Rationnel(pow(A.getNumerateur(),float(B)),pow(A.getDenumerateur(),float(B)));
                             stack->empiler(dC);
                        }

                break;

        }
    }

    else if ( testE1 || testE2){    //On a forcément deux entiers

                Entier* C = new Entier;

                // Il est inutile de creer des variables locales entieres et de proceder a une conversion a partir de donnee, puisque testE1 et testE2 sont tout les 2 forcéments des entiers. Nous pouvons donc les utiliser dans le calcul.

            switch (typeoperation) {

                case (PLUS):
                            {
                                *C = *testE1 + *testE2;
                                stack->empiler(C);
                            }

                    break;

                case(MINUS):
                            {
                                *C = *testE1 - *testE2;
                                stack->empiler(C);

                            }
                    break;


                case(DIV):

                            {
                            if (testE2->getVal()==0){
                                                stack->empiler(testE1);
                                                stack->empiler(testE2);
                                                throw CalculException("Division par zero impossible.");
                                            }

                            else {
                                    *C = *testE1 / *testE2;
                                    stack->empiler(C);
                                }



                            }
                    break;

                case (MULT):

                            {
                                *C = *testE1 * *testE2;
                                stack->empiler(C);
                            }
                    break;

                case(MODULO):

                            {
                                if (testE2->getVal()==0){
                                                            stack->empiler(testE1);
                                                            stack->empiler(testE2);
                                                            throw CalculException("Modulo: Division par zero impossible.");
                                                        }

                                else {
                                        *C = *testE1 % *testE2;
                                        stack->empiler(C);
                                     }

                            }
                    break;

                case (POW):
                            {
                                *C = Entier(pow(testE1->getVal(),testE2->getVal()));
                                stack->empiler(C);
                            }

                    break;

            }

    }

    else throw CalculException("Echec de la reconnaissance du type de 2 variables entrees.\nSource: Operateurbinaire.cpp. ");

    }
}

void OperateurBinaire::afficher(std::ostream& f) const
{
    switch(typeoperation)
    {
        case(PLUS): f<<"+"; break;
        case(MINUS): f<<"-"; break;
        case(DIV): f<<"/"; break;
        case(MULT): f<<"*"; break;
        case(MODULO): f<<"MOD"; break;
        case(POW): f<<"^"; break;
        default : throw CalculException("Type d'operateur inconnu."); break;
    }
}

Donnee* OperateurBinaire::clone() const
{
    return new OperateurBinaire(typeoperation);
}
