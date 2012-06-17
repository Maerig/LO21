#include "operateurbinaire.h"
#include "calculexception.h"

#include <iostream>
#include <math.h>

//enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};

void OperateurBinaire::Calculer(Pile* stack){

    Donnee* dB= stack->depiler();
    Donnee* dA= stack->depiler();

    Expression* testExA =dynamic_cast<Expression*>(dA);
    Expression* testExB =dynamic_cast<Expression*>(dB);

    if (testExA) {
        testExA->enfiler_fin(dB);
        testExA->enfiler_fin(this);
        stack->empiler(testExA);
    }

    else if (testExB) {
        testExA->enfiler_debut(dA);
        testExA->enfiler_fin(this);
        stack->empiler(testExA);
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


    if ( testC1 || testC2){    //On a au moins un complexe

        //Complexe A(0);
        //Complexe B(0);

        //METHODE 1
        Complexe A= Complexe(dA);
        Complexe B= Complexe(dB);


        /* METHODE 2
        if (!testC1){                                               // On entre dans A le complexe testC1=dA, apres conversion si necessaire.
                        if (!test1) A=Complexe(*test1);
                        else if (!test3) A=Complexe(*test3);        // On cherche le test(i) non nul, c'est  dire le vritable type de dA. On construit  partir de a le complexe.
                        else A=Complexe(*testE1);
                   }
        else A=*testC1;

        if (!testC2){                                               // On entre dans B le complexe testC2=dB, apres conversion si necessaire.
                        if (!test2) A=Complexe(*test2);
                        else if (!test4) A=Complexe(*test4);
                        else A=Complexe(*testE2);
                   }
        else B=*testC2;
        */


            switch (typeoperation) {

                case (PLUS):
                {
                    Complexe dC=(A+B);
                    stack->empiler(&dC);
                }

                    break;

                case(MINUS):
                {
                    Complexe dC=(A-B);
                    stack->empiler(&dC);
                }
                    break;


                case(DIV):
                {
                    Complexe dC=(A/B);
                    stack->empiler(&dC);
                }
                    break;

                case (MULT):
                {
                    Complexe dC=(A*B);
                    stack->empiler(&dC);
                }
                    break;

                case(MODULO):
                {
                    stack->empiler(dA);
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

        Reel A(0);
        Reel B(0);

        if (!test1){
                        if (!test3) A=Reel(*testE1);
                         else A=Reel(*test3);
                   }
        else A=*test1;

        if (!test2)
            {
                if (!test4) B=Reel(*testE2);
                 else B=Reel(*test4);
            }
        else B=*test2;

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

                    if (B.getVal()==0){
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

        Rationnel A(0);
        Rationnel B(0);

        if (!test3){
                        A=Rationnel(*testE1);
                   }
        else A=*test3;

        if (!test4)
                    {
                        B=Rationnel(*test4);
                    }
        else B=*test4;

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
