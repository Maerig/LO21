#include "operateurbinaire.h"

//enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};

void OperateurBinaire::Calculer(Pile* stack){

    Donnee* dB= stack->depiler();
    Donnee* dA= stack->depiler();

    const Reel* test1 = dynamic_cast<const Reel*>(dA);
    const Reel* test2 = dynamic_cast<const Reel*>(dB);
    const Rationnel* test3 = dynamic_cast<const Rationnel*>(dA);
    const Rationnel* test4 = dynamic_cast<const Rationnel*>(dB);
    const Entier* test5 = dynamic_cast<const Entier*>(dA);
    const Entier* test6 = dynamic_cast<const Entier*>(dB);


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

    else if ( *test5 || *test6){

            switch (typeoperation) {
                case (PLUS):

                    {
                            const Entier A=*test5;
                            const Entier B=*test6;

                            Entier C(A+B);
                            Entier* dC=&C;
                            stack->empiler(dC);
                    }
                    break;
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
