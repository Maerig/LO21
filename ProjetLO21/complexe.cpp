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

Complexe::Complexe(Donnee* Re)
{
        Reel* test1 = dynamic_cast< Reel*>(Re);
        Rationnel* test2 = dynamic_cast< Rationnel*>(Re);
        Entier* test3 = dynamic_cast< Entier*>(Re);

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

Complexe::Complexe(){
    a= new Reel;
    b= new Reel;
}
