#include "complexe.h"

void Complexe::afficher(std::ostream& f) const
{
    a->afficher(f);
    f<<" + ";
    b->afficher(f);
    f<<"i";
}

Donnee* Complexe::clone() const
{
    Nombre* num1 = dynamic_cast <Nombre*>(a->clone());
    Nombre* num2 = dynamic_cast <Nombre*>(b->clone());
    return new Complexe(num1,num2);
}
