#include "expression.h"
#include "pile.h"
#include "calculexception.h"
#include <typeinfo>
#include "factory.h"


Expression::Expression(std::string str)
{
    Factory fact;
    tete = new Cellule(fact.make(str));
}

void Expression::afficher(std::ostream& f) const {
    Cellule* cell = tete;
    if(cell)
    {
        f<<"'";
        while(cell)
        {
            cell->getContent()->afficher(f);
            cell = cell->getSucc();
            if(cell) f<<" ";
        }
        f<<"'";
    }
    else
        throw CalculException("Expression vide.");
}

Donnee* Expression::clone() const {
    if(!tete)
    {
        throw CalculException("Expression vide.");
        return 0;
    }
    Cellule* cell = new Cellule(tete->getContent()->clone());
    Cellule* newhead = cell;
    Cellule* next = tete->getSucc();
    while(next)
    {
        Cellule* tmp = new Cellule(next->getContent()->clone());
        cell->setSucc(tmp);
        next = next->getSucc();
    }
    return new Expression(newhead);
}

bool Expression::valide() const //Verifie que la syntaxe de l'expression est conforme a la notation polonaise inversee
{
    Pile stack;
    Cellule* cell = tete;
    Donnee* data1;
    Donnee* data2;
    while(cell)
    {
        //On teste si le contenu de la cellule est de type Numerique
        const Numerique* test = dynamic_cast<const Numerique*>(cell->getContent());
        if (test)
            stack.empiler(cell->getContent());
        else    //Il d'agit d'un operateur
        {
            if (stack.longueur()<2)
                return false;
            data1 = stack.depiler();
            data2 = stack.depiler();
            const Numerique* test1 = dynamic_cast<const Numerique*>(data1);
            const Numerique* test2 = dynamic_cast<const Numerique*>(data2);
            if (!(test1 && test2))
                    return false;
            stack.empiler(data1);
        }
        cell = cell->getSucc();
    }
    data1 = stack.depiler();
    const Numerique* test = dynamic_cast<const Numerique*>(data1);
    if(test)
        return true;
    return false;
}
