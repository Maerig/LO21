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

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<"+";
    b->afficher(f);
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
