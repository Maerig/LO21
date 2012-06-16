#include "operateurbinaire.h"
#include "calculexception.h"

#include <iostream>
#include <math.h>

//enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};

void OperateurBinaire::Calculer(Pile* stack){

    Donnee* dB= stack->depiler();
    Donnee* dA= stack->depiler();

    Reel* test1 = dynamic_cast< Reel*>(dA);
    Reel* test2 = dynamic_cast< Reel*>(dB);
    Rationnel* test3 = dynamic_cast< Rationnel*>(dA);
    Rationnel* test4 = dynamic_cast< Rationnel*>(dB);
    Entier* test5 = dynamic_cast< Entier*>(dA);
    Entier* test6 = dynamic_cast< Entier*>(dB);


    if ( test1 || test2 ) {     //Au moins un reel

        Reel A(0);
        Reel B(0);

        if (!test1){
                        if (!test3) A=Reel(*test5);
                         else A=Reel(*test3);
                   }
        else A=*test1;

        if (!test2)
            {
                if (!test4) B=Reel(*test6);
                 else B=Reel(*test4);
            }
        else B=*test2;


        switch (typeoperation) {
            case (PLUS):
                        {
                                    Reel* dC = new Reel;
                                    *dC=(A+B);
                                    stack->empiler(dC);
                        }
                break;

            case(MINUS):
        {
                    Reel* dC = new Reel;
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
                        Reel* dC = new Reel;
                        *dC=(A/B);
                        stack->empiler(dC);
                        }
        }

                break;

            case (MULT):
        {
                    Reel* dC = new Reel;
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
                    Reel* dC = new Reel;
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
                        A=Rationnel(*test5);
                   }
        else A=*test3;

        if (!test4)
                    {
                        B=Rationnel(*test4);
                    }
        else B=*test4;



            switch (typeoperation) {
            case (PLUS):
                       {
                            Rationnel* dC = new Rationnel;
                            *dC=(A+B);
                            stack->empiler(dC);
                       }
                break;
            case(MINUS):
            {
                 Rationnel* dC = new Rationnel;
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
                     Rationnel* dC = new Rationnel;
                     *dC=(A/B);
                     stack->empiler(dC);
                     }
            }

                break;

            case (MULT):
            {
                 Rationnel* dC = new Rationnel;
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
                 Rationnel* dC = new Rationnel;
                 *dC=Rationnel(pow(A.getNumerateur(),float(B)),pow(A.getDenumerateur(),float(B)));
                 stack->empiler(dC);
            }

                break;

        }
    }

    else if ( *test5 || *test6){    //On a forcément deux entiers

            switch (typeoperation) {

                case (PLUS):
                {
                    Entier* C = new Entier;
                    *C = *test5 + *test6;
                    stack->empiler(C);
                }

                    break;

                case(MINUS):
                {
                    Entier* C = new Entier;
                    *C = *test5 - *test6;
                    stack->empiler(C);

                }
                    break;


                case(DIV):

                {
                if (test6->getVal()==0){
                                    stack->empiler(test5);
                                    stack->empiler(test6);
                                    throw CalculException("Division par zero impossible.");
                                }

                else {
                        Entier* C = new Entier;
                        *C = *test5 / *test6;
                        stack->empiler(C);
                    }



                }
                    break;

                case (MULT):

                {
                    Entier* C = new Entier;
                    *C = *test5 * *test6;
                    stack->empiler(C);
                }
                    break;

                case(MODULO):

                {
                    if (test6->getVal()==0){
                                                stack->empiler(test5);
                                                stack->empiler(test6);
                                                throw CalculException("Modulo: Division par zero impossible.");
                                            }

                    else {
                            Entier* C = new Entier;
                            *C = *test5 % *test6;
                            stack->empiler(C);
                         }

                }
                    break;

                case (POW):
                {
                    Entier* C = new Entier;
                    *C = Entier(pow(test5->getVal(),test6->getVal()));
                    stack->empiler(C);
                }

                    break;

            }

    }

    else throw CalculException("Echec de la reconnaissance du type des 2 dernieres variables entrees.\nSource: Operateurbinaire.cpp. ");
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
