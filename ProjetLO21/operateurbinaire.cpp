#include "operateurbinaire.h"
#include "calculexception.h"

#include <iostream>

//enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};

OperateurBinaire::OperateurBinaire(std::string str)
{
    if(str=="+")
        typeoperation = PLUS;
}

void OperateurBinaire::Calculer(Pile* stack){

    Donnee* dB= stack->depiler();
    Donnee* dA= stack->depiler();

    Reel* test1 = dynamic_cast< Reel*>(dA);
    Reel* test2 = dynamic_cast< Reel*>(dB);
    Rationnel* test3 = dynamic_cast< Rationnel*>(dA);
    Rationnel* test4 = dynamic_cast< Rationnel*>(dB);
    Entier* test5 = dynamic_cast< Entier*>(dA);
    Entier* test6 = dynamic_cast< Entier*>(dB);


    if ( test1 || test2 ) {

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

                break;

            case(DIV):

                break;

            case (MULT):

                break;

            case(MODULO):

                break;

            case (POW):

                break;

        }
    }

    else if ( test3 || test4 ) {

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

                break;

            case(DIV):

                break;

            case (MULT):

                break;

            case(MODULO):

                break;

            case (POW):

                break;

        }
    }

    else if ( *test5 || *test6){    //On a forcément deux entiers

            switch (typeoperation) {

                case (PLUS):
                {
                    Entier* C = new Entier;
                    std::cerr<<"Passe 1\n";
                    test5->afficher(std::cerr);
                    test6->afficher(std::cerr);
                    *C = *test5 + *test6;
                    std::cerr<<"C = ";
                    C->afficher(std::cerr);
                    stack->empiler(C);
                }

                    break;

                case(MINUS):{


		}
		    break;


                case(DIV):

                {
                        
                }
                    break;

                case (MULT):

                {
                    const Entier A=*test5;
                    const Entier B=*test6;

                    Entier C(A*B);
                    Entier* dC=&C;
                    stack->empiler(dC);
                }
                    break;

                case(MODULO):

                {

                }
                    break;

                case (POW):

                    break;

            }

    }

}


void OperateurBinaire::afficher(std::ostream& f) const
{
    switch(typeoperation)
    {
        case(PLUS): f<<"+"; break;
        default : throw CalculException("Type d'operateur inconnu."); break;
    }
}

Donnee* OperateurBinaire::clone() const
{
    return new OperateurBinaire(typeoperation);
}
