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

    stack->afficher(std::cerr);
    Donnee* dB= stack->depiler();
    Donnee* dA= stack->depiler();

    const Reel* test1 = dynamic_cast<const Reel*>(dA);
    const Reel* test2 = dynamic_cast<const Reel*>(dB);
    const Rationnel* test3 = dynamic_cast<const Rationnel*>(dA);
    const Rationnel* test4 = dynamic_cast<const Rationnel*>(dB);
    const Entier* test5 = dynamic_cast<const Entier*>(dA);
    const Entier* test6 = dynamic_cast<const Entier*>(dB);
    /*
    Reel dA(3.4);
    Reel dB(11.3);

    Reel* A1=&dA;
    Reel* B1=&dB;

    const Reel* test1 = dynamic_cast<const Reel*>(A1);
    const Reel* test2 = dynamic_cast<const Reel*>(B1);


    if ( test1 || test2 ) {

            const Reel A=*test1;
            const Reel B=*test2;
            Reel C(A+B);
            std::cout<<C.getVal();
   }*/


    if ( test1 || test2 ) {

        switch (typeoperation) {
        case (PLUS):
{
            const Reel A=*test1;
            const Reel B=*test2;
            Reel C(A+B);

            Reel* dC=&C;
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

            switch (typeoperation) {
            case (PLUS):
    {
                const Reel A=*test1;
                const Reel B=*test2;
                Reel C(A+B);

                Reel* dC=&C;
                stack->empiler(dC);

                break;
    }
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
                break;
            }
            case(MINUS):
            {
                    const Entier A=*test5;
                    const Entier B=*test6;

                    Entier C(A-B);
                    Entier* dC=&C;
                    stack->empiler(dC);
            }

                break;

            case(DIV):
            {
                    const Entier A=*test5;
                    const Entier B=*test6;

                    Entier C(A/B);
                    Entier* dC=&C;
                    stack->empiler(dC);
            }
                    break;


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
