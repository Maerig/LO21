#include "complexe.h"
#include "calculexception.h"


Complexe::Complexe(Donnee* Re, Donnee* Im)
{
    Nombre* num1 = dynamic_cast <Nombre*>(Re);
    Nombre* num2 = dynamic_cast <Nombre*>(Im);
    if(num1&&num2)
    {
        a=num1;
        b=num2;
    }
    else
        throw CalculException("Un complexe ne peut etre forme que de nombres.");
}

Complexe::Complexe(){
    a= new Reel;
    b= new Reel;
}

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<"+";
    b->afficher(f);
    f<<"i";
}

void Complexe::afficher_contexte(std::ostream& f) const
{
    f<<"Complexe:";
    a->afficher_contexte(f);
    f<<"+";
    b->afficher_contexte(f);
    f<<"i";
}

Donnee* Complexe::clone() const
{

    return new Complexe(a->clone(),b->clone());
}

bool complexe_like(std::string str)
{
    int i=0;
    std::string re,im;
    if(str[0]=='$')
        return false;
    while(str[i]&&str[i]!='$')
        re+=str[i++];
    ++i;
    while(str[i])
        im+=str[i++];
    return (number(re)&&number(im));
}

bool saved_complexe(std::string str)    //Verifie qu'il s'agit d'un complexe sous sa forme affichee
{
    int i=0;
    std::string re,im;
    if(!number(str[i]))
        return false;
    while(str[i]&&str[i]!='+')
        re+=str[i++];
    ++i;
    while(str[i]&&str[i]!='i')
        im+=str[i++];
    return (number(re)&&number(im)&&str[i]=='i'&&str[i+1]=='\0');
}

Complexe& Complexe::operator=(const Complexe& n){
    if(this != &n){
            a=n.a;
            b=n.b;
    }
    return *this;
}

Complexe& Complexe::operator+(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.
    Complexe* A=this;

    Reel* A_a1 = dynamic_cast< Reel*>(A->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(A->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(A->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);

    // Il suffit de prendre en considération le type d'un attribut par complexe. Le second étant obligatoirement du meme type.


    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a(0);
        Reel A_b(0);
        Reel B_a(0);
        Reel B_b(0);

        if (!A_a1){                        // Si A_a1 null, donc les attributs de A n'est pas reel. Il faut les convertir en reels.
                        if (!A_a2) {
                                        A_a=Reel(*A_a2);
                                        A_b=Reel(*dynamic_cast<Rationnel*>(A->b));
                                    }

                        else {
                                A_a=Reel(*A_a3);
                                A_b=Reel(*dynamic_cast<Entier*>(A->b));
                             }
                   }
        else {
                A_a=*A_a1;
                A_b=(*dynamic_cast<Reel*>(A->b));
             }

        if (!B_a1){
                        if (!B_a2) {
                                        B_a=Reel(*B_a2);
                                        B_b=Reel(*dynamic_cast<Rationnel*>(B.b));
                                    }

                        else {
                                B_a=Reel(*B_a3);
                                B_b=Reel(*dynamic_cast<Entier*>(B.b));
                             }
                   }
        else {
                B_a=*B_a1;
                B_b=(*dynamic_cast<Reel*>(B.b));
             }

        Reel* p_r= new Reel;
        Reel* p_im= new Reel;

        *p_r=(A_a+B_a);
        *p_im=(A_b+B_b);

        Complexe tmp(p_r,p_im);
        return tmp;
    }

    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a(0);
        Rationnel A_b(0);
        Rationnel B_a(0);
        Rationnel B_b(0);

        if (!A_a2){                        // Si A_a1 null, donc les attributs de A n'est pas rationnel. Il faut les convertir en rationnels.
                                A_a=Rationnel(*A_a3);
                                A_b=Rationnel(*dynamic_cast<Entier*>(A->b));
                   }
        else {
                A_a=*A_a2;
                A_b=(*dynamic_cast<Rationnel*>(A->b));
             }

        if (!B_a2){
                                B_a=Rationnel(*B_a3);
                                B_b=Rationnel(*dynamic_cast<Entier*>(B.b));

                   }
        else {
                B_a=*B_a2;
                B_b=(*dynamic_cast<Rationnel*>(B.b));
             }

        Rationnel* p_r= new Rationnel;
        Rationnel* p_im= new Rationnel;

        *p_r=(A_a+B_a);
        *p_im=(A_b+B_b);

        Complexe tmp(p_r,p_im);
        return tmp;
    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a(0);
        Entier A_b(0);
        Entier B_a(0);
        Entier B_b(0);

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(A->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));


         Entier* p_r= new Entier;
         Entier* p_im= new Entier;

         *p_r=(A_a+B_a);
         *p_im=(A_b+B_b);

         Complexe tmp(p_r,p_im);
         return tmp;
    }

    else throw CalculException("Imprevu: donnee complexes non reconnus.\nCf complexe.cpp");

}

Complexe& Complexe::operator-(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.
    Complexe* A=this;

    Reel* A_a1 = dynamic_cast< Reel*>(A->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(A->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(A->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);




    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a(0);
        Reel A_b(0);
        Reel B_a(0);
        Reel B_b(0);

        if (!A_a1){                        // Si A_a1 null, donc les attributs de A n'est pas reel. Il faut les convertir en reels.
                        if (!A_a2) {
                                        A_a=Reel(*A_a2);
                                        A_b=Reel(*dynamic_cast<Rationnel*>(A->b));
                                    }

                        else {
                                A_a=Reel(*A_a3);
                                A_b=Reel(*dynamic_cast<Entier*>(A->b));
                             }
                   }
        else {
                A_a=*A_a1;
                A_b=(*dynamic_cast<Reel*>(A->b));
             }

        if (!B_a1){
                        if (!B_a2) {
                                        B_a=Reel(*B_a2);
                                        B_b=Reel(*dynamic_cast<Rationnel*>(B.b));
                                    }

                        else {
                                B_a=Reel(*B_a3);
                                B_b=Reel(*dynamic_cast<Entier*>(B.b));
                             }
                   }
        else {
                B_a=*B_a1;
                B_b=(*dynamic_cast<Reel*>(B.b));
             }

        Reel* p_r= new Reel;
        Reel* p_im= new Reel;

        *p_r=(A_a-B_a);
        *p_im=(A_b-B_b);

        Complexe tmp(p_r,p_im);

        return tmp;

    }


    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a(0);
        Rationnel A_b(0);
        Rationnel B_a(0);
        Rationnel B_b(0);

        if (!A_a2){                        // Si A_a1 null, donc les attributs de A n'est pas rationnel. Il faut les convertir en rationnels.
                                A_a=Rationnel(*A_a3);
                                A_b=Rationnel(*dynamic_cast<Entier*>(A->b));
                   }
        else {
                A_a=*A_a2;
                A_b=(*dynamic_cast<Rationnel*>(A->b));
             }

        if (!B_a2){
                                B_a=Rationnel(*B_a3);
                                B_b=Rationnel(*dynamic_cast<Entier*>(B.b));

                   }
        else {
                B_a=*B_a2;
                B_b=(*dynamic_cast<Rationnel*>(B.b));
             }

        Rationnel* p_r= new Rationnel;
        Rationnel* p_im= new Rationnel;
        *p_r=(A_a-B_a);
        *p_im=(A_b-B_b);

        Complexe tmp(p_r,p_im);

        return tmp;


    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a(0);
        Entier A_b(0);
        Entier B_a(0);
        Entier B_b(0);

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(A->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));

         Entier* p_r= new Entier;
         Entier* p_im= new Entier;

         *p_r=(A_a-B_a);
         *p_im=(A_b-B_b);

         Complexe tmp(p_r,p_im);

         return tmp;
    }

    else throw CalculException("Imprevu: donne complexes non reconnus.\nCf complexe.cpp");
}

Complexe& Complexe::operator/(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.
    Complexe* A=this;

    Reel* A_a1 = dynamic_cast< Reel*>(A->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(A->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(A->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);




    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a(0);
        Reel A_b(0);
        Reel B_a(0);
        Reel B_b(0);

        if (!A_a1){                        // Si A_a1 null, donc les attributs de A n'est pas reel. Il faut les convertir en reels.
                        if (!A_a2) {
                                        A_a=Reel(*A_a2);
                                        A_b=Reel(*dynamic_cast<Rationnel*>(A->b));
                                    }

                        else {
                                A_a=Reel(*A_a3);
                                A_b=Reel(*dynamic_cast<Entier*>(A->b));
                             }
                   }
        else {
                A_a=*A_a1;
                A_b=(*dynamic_cast<Reel*>(A->b));
             }

        if (!B_a1){
                        if (!B_a2) {
                                        B_a=Reel(*B_a2);
                                        B_b=Reel(*dynamic_cast<Rationnel*>(B.b));
                                    }

                        else {
                                B_a=Reel(*B_a3);
                                B_b=Reel(*dynamic_cast<Entier*>(B.b));
                             }
                   }
        else {
                B_a=*B_a1;
                B_b=(*dynamic_cast<Reel*>(B.b));
             }

        Reel* p_r= new Reel;
        Reel* p_im= new Reel;

        *p_r= ( ((A_a*B_a) + (A_b*B_b)) / ((B_a*B_a) + (B_b*B_b)) );
        *p_im=( ((A_b*B_a) - (A_a*B_b)) / ((B_a*B_a) + (B_b*B_b)) );

        Complexe tmp(p_r,p_im);

        return tmp;
    }


    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a(0);
        Rationnel A_b(0);
        Rationnel B_a(0);
        Rationnel B_b(0);

        if (!A_a2){                        // Si A_a1 null, donc les attributs de A n'est pas rationnel. Il faut les convertir en rationnels.
                                A_a=Rationnel(*A_a3);
                                A_b=Rationnel(*dynamic_cast<Entier*>(A->b));
                   }
        else {
                A_a=*A_a2;
                A_b=(*dynamic_cast<Rationnel*>(A->b));
             }

        if (!B_a2){
                                B_a=Rationnel(*B_a3);
                                B_b=Rationnel(*dynamic_cast<Entier*>(B.b));

                   }
        else {
                B_a=*B_a2;
                B_b=(*dynamic_cast<Rationnel*>(B.b));
             }

        Rationnel* p_r= new Rationnel;
        Rationnel* p_im= new Rationnel;

        *p_r=(A_a+B_a);
        *p_im=(A_b+B_b);

        Complexe tmp(p_r,p_im);

        return tmp;
    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a(0);
        Entier A_b(0);
        Entier B_a(0);
        Entier B_b(0);

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(A->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));


         Entier* p_r= new Entier;
         Entier* p_im= new Entier;
         *p_r=(A_a+B_a);
         *p_im=(A_b+B_b);

         Complexe tmp(p_r,p_im);

         return tmp;
    }

    else throw CalculException("Imprevu: donne complexes non reconnus.\nCf complexe.cpp");

}


Complexe& Complexe::operator*(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.
    Complexe* A=this;

    Reel* A_a1 = dynamic_cast< Reel*>(A->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(A->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(A->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);




    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a(0);
        Reel A_b(0);
        Reel B_a(0);
        Reel B_b(0);

        if (!A_a1){                        // Si A_a1 null, donc les attributs de A n'est pas reel. Il faut les convertir en reels.
                        if (!A_a2) {
                                        A_a=Reel(*A_a2);
                                        A_b=Reel(*dynamic_cast<Rationnel*>(A->b));
                                    }

                        else {
                                A_a=Reel(*A_a3);
                                A_b=Reel(*dynamic_cast<Entier*>(A->b));
                             }
                   }
        else {
                A_a=*A_a1;
                A_b=(*dynamic_cast<Reel*>(A->b));
             }

        if (!B_a1){
                        if (!B_a2) {
                                        B_a=Reel(*B_a2);
                                        B_b=Reel(*dynamic_cast<Rationnel*>(B.b));
                                    }

                        else {
                                B_a=Reel(*B_a3);
                                B_b=Reel(*dynamic_cast<Entier*>(B.b));
                             }
                   }
        else {
                B_a=*B_a1;
                B_b=(*dynamic_cast<Reel*>(B.b));
             }

        Reel* p_r= new Reel;
        Reel* p_im= new Reel;


        *p_r= ( (A_a*B_a) - (A_b*B_b) );
        *p_im=( (A_a*B_b) + (A_b*B_a) );

        Complexe tmp(p_r,p_im);

        return tmp;


    }


    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a(0);
        Rationnel A_b(0);
        Rationnel B_a(0);
        Rationnel B_b(0);

        if (!A_a2){                        // Si A_a1 null, donc les attributs de A n'est pas rationnel. Il faut les convertir en rationnels.
                                A_a=Rationnel(*A_a3);
                                A_b=Rationnel(*dynamic_cast<Entier*>(A->b));
                   }
        else {
                A_a=*A_a2;
                A_b=(*dynamic_cast<Rationnel*>(A->b));
             }

        if (!B_a2){
                                B_a=Rationnel(*B_a3);
                                B_b=Rationnel(*dynamic_cast<Entier*>(B.b));

                   }
        else {
                B_a=*B_a2;
                B_b=(*dynamic_cast<Rationnel*>(B.b));
             }

        Rationnel* p_r= new Rationnel;
        Rationnel* p_im= new Rationnel;


        *p_r= ( (A_a*B_a) - (A_b*B_b) );
        *p_im=( (A_a*B_b) + (A_b*B_a) );

        Complexe tmp(p_r,p_im);

        return tmp;
    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a(0);
        Entier A_b(0);
        Entier B_a(0);
        Entier B_b(0);

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(A->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));


         Entier* p_r= new Entier;
         Entier* p_im= new Entier;

         *p_r= ( (A_a*B_a) - (A_b*B_b) );
         *p_im=( (A_a*B_b) + (A_b*B_a) );

         Complexe tmp(p_r,p_im);

         return tmp;
    }

    else throw CalculException("Imprevu: donne complexes non reconnus.\nCf complexe.cpp");

}

/*
Complexe::Complexe(Donnee* d)                   // Pour methode 1
{
        Reel* test1 = dynamic_cast< Reel*>(d);
        Rationnel* test2 = dynamic_cast< Rationnel*>(d);
        Entier* test3 = dynamic_cast< Entier*>(d);

        if (test1){
                   a=test1;
                   b=new Reel;
                  }
        else if (test2){
                   a=test2;
                   b= new Rationnel;
                  }
        else if (test3){
                   a=test3;
                   b=new Entier;
                  }

        else throw CalculException("Erreur inattendue au niveau de la formation d'un complexe par une donne. Cf complexe.cpp");

}
*/


// MEthode 2

Complexe::Complexe(Reel r){

    a=new Reel;
    *a=r;

    b=new Reel;

}

Complexe::Complexe(Rationnel r){

    a=new Rationnel;
    *a=r;

    b=new Rationnel;
}

Complexe::Complexe(Entier e){

    a=new Entier;
    *a=e;

    b=new Entier;
}



