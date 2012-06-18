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


Complexe::Complexe(Donnee *d)
{
        Complexe* test = dynamic_cast< Complexe*>(d);
        Reel* test1 = dynamic_cast< Reel*>(d);
        Rationnel* test2 = dynamic_cast< Rationnel*>(d);
        Entier* test3 = dynamic_cast< Entier*>(d);

        if (test) {
                    a=test->a;
                    b=test->b;
        }

        else if (test1){
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

    Reel* A_a1 = dynamic_cast< Reel*>(this->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(this->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(this->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);

    // Il suffit de prendre en considération le type d'un attribut par complexe. Le second étant obligatoirement du meme type.


    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a=Reel(this->a);
        Reel A_b=Reel(this->b);
        Reel B_a=Reel(B.a);
        Reel B_b=Reel(B.b);

        Reel* p_r= new Reel(A_a+B_a);
        Reel* p_im= new Reel(A_b+B_b);

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;

    }

    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a=Rationnel(this->a);
        Rationnel A_b=Rationnel(this->b);
        Rationnel B_a=Rationnel(B.a);
        Rationnel B_b=Rationnel(B.b);

        Rationnel* p_r= new Rationnel(A_a+B_a);
        Rationnel* p_im= new Rationnel(A_b+B_b);

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;

    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a;
        Entier A_b;
        Entier B_a;
        Entier B_b;

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(this->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));


         Entier* p_r= new Entier(A_a+B_a);
         Entier* p_im= new Entier(A_b+B_b);

         Complexe* tmp = new Complexe(p_r,p_im);
         return *tmp;
    }

    else throw CalculException("Imprevu: donnee complexes non reconnus.\nCf + complexe.cpp");

}

Complexe& Complexe::operator-(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.

    Reel* A_a1 = dynamic_cast< Reel*>(this->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(this->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(this->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);




    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a=Reel(this->a);
        Reel A_b=Reel(this->b);
        Reel B_a=Reel(B.a);
        Reel B_b=Reel(B.b);

        Reel* p_r= new Reel(A_a-B_a);
        Reel* p_im= new Reel(A_b-B_b);

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;

    }


    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a=Rationnel(this->a);
        Rationnel A_b=Rationnel(this->b);
        Rationnel B_a=Rationnel(B.a);
        Rationnel B_b=Rationnel(B.b);

        Rationnel* p_r= new Rationnel(A_a-B_a);
        Rationnel* p_im= new Rationnel(A_b-B_b);

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;


    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a;
        Entier A_b;
        Entier B_a;
        Entier B_b;

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(this->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));

         Entier* p_r= new Entier(A_a-B_a);
         Entier* p_im= new Entier(A_b-B_b);

         Complexe* tmp = new Complexe(p_r,p_im);
         return *tmp;
    }

    else throw CalculException("Imprevu: donne complexes non reconnus.\nCf - complexe.cpp");
}

Complexe& Complexe::operator/(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.

    Reel* A_a1 = dynamic_cast< Reel*>(this->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(this->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(this->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);




    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a=Reel(this->a);
        Reel A_b=Reel(this->b);
        Reel B_a=Reel(B.a);
        Reel B_b=Reel(B.b);

        Reel* p_r= new Reel( ((A_a*B_a) + (A_b*B_b)) / ((B_a*B_a) + (B_b*B_b)) );
        Reel* p_im= new Reel( ((A_b*B_a) - (A_a*B_b)) / ((B_a*B_a) + (B_b*B_b)) );

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;
    }


    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a=Rationnel(this->a);
        Rationnel A_b=Rationnel(this->b);
        Rationnel B_a=Rationnel(B.a);
        Rationnel B_b=Rationnel(B.b);

        Rationnel* p_r= new Rationnel( ((A_a*B_a) + (A_b*B_b)) / ((B_a*B_a) + (B_b*B_b)) );
        Rationnel* p_im= new Rationnel( ((A_b*B_a) - (A_a*B_b)) / ((B_a*B_a) + (B_b*B_b)) );

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;
    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a;
        Entier A_b;
        Entier B_a;
        Entier B_b;

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(this->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));

         Entier* p_r= new Entier( ((A_a*B_a) + (A_b*B_b)) / ((B_a*B_a) + (B_b*B_b)) );
         Entier* p_im= new Entier( ((A_b*B_a) - (A_a*B_b)) / ((B_a*B_a) + (B_b*B_b)) );

         Complexe* tmp = new Complexe(p_r,p_im);
         return *tmp;
    }

    else throw CalculException("Imprevu: donnee complexes non reconnus.\nCf / complexe.cpp");

}


Complexe& Complexe::operator*(const Complexe& B){

    // A Et B sont complexes, mais leur attribut a et b peuvent etre de types different. Il faut donc unifier.

    Reel* A_a1 = dynamic_cast< Reel*>(this->a);
    Reel* B_a1 = dynamic_cast< Reel*>(B.a);
    Rationnel* A_a2 = dynamic_cast< Rationnel*>(this->a);
    Rationnel* B_a2 = dynamic_cast< Rationnel*>(B.a);
    Entier* A_a3 = dynamic_cast< Entier*>(this->a);
    Entier* B_a3 = dynamic_cast< Entier*>(B.a);


    // Il suffit d'étudier un attribut par complexe. Le second étant obligatoirement du meme type.

    if (A_a1 || B_a1)                       // L'attribut a de A ou de B est reel, tout les attributs doivent donc devenir reels.
    {
        Reel A_a=Reel(this->a);
        Reel A_b=Reel(this->b);
        Reel B_a=Reel(B.a);
        Reel B_b=Reel(B.b);

        Reel* p_r= new Reel( (A_a*B_a) - (A_b*B_b) );
        Reel* p_im= new Reel( (A_a*B_b) + (A_b*B_a) );

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;
    }

    else if (A_a2 || B_a2)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Rationnel A_a=Rationnel(this->a);
        Rationnel A_b=Rationnel(this->b);
        Rationnel B_a=Rationnel(B.a);
        Rationnel B_b=Rationnel(B.b);

        Rationnel* p_r= new Rationnel( (A_a*B_a) - (A_b*B_b) );
        Rationnel* p_im= new Rationnel( (A_a*B_b) + (A_b*B_a) );

        Complexe* tmp = new Complexe(p_r,p_im);
        return *tmp;
    }

    else if (A_a3 || B_a3)                       // L'attribut a de A ou de B est rationnel, tout les attributs doivent donc devenir rationnels.
    {
        Entier A_a(0);
        Entier A_b(0);
        Entier B_a(0);
        Entier B_b(0);

         A_a=*A_a3;
         A_b=(*dynamic_cast<Entier*>(this->b));

         B_a=*B_a3;
         B_b=(*dynamic_cast<Entier*>(B.b));


         Entier* p_r= new Entier( (A_a*B_a) - (A_b*B_b) );
         Entier* p_im= new Entier( (A_a*B_b) + (A_b*B_a) );

         Complexe* tmp = new Complexe(p_r,p_im);
         return *tmp;
    }

    else throw CalculException("Imprevu: donne complexes non reconnus.\nCf * complexe.cpp");

}


