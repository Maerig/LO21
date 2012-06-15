#include "expression.h"
#include "pile.h"
#include "calculexception.h"
#include <typeinfo>
#include "factory.h"

#include <iostream>


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
        cell->setSucc(new Cellule(next->getContent()->clone()));
        next = next->getSucc();
        cell = cell->getSucc();
    }
    return new Expression(newhead,taille);
}

bool Expression::valide() const //Verifie que la syntaxe de l'expression est conforme a la notation polonaise inversee
{
    Pile stack;
    Expression* copy =  dynamic_cast<Expression*>(clone());
    Cellule* cell = copy->tete;
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

void Expression::enfiler_debut(Donnee *elt)
{
    Expression* exp = dynamic_cast<Expression*>(elt);  //Si on enfile une expression
    if(exp)
    {
        taille += exp->longueur();
        exp->enfiler_fin(this); //Cela revient a enfiler la premiere a la fin de la seconde
        tete = exp->tete;
    }
    else
    {
        tete = new Cellule(elt,tete);
        ++taille;
    }
}

void Expression::enfiler_fin(Donnee *elt)
{
    if(!tete)
        throw CalculException("Expression vide.");
    else
    {
        Cellule* cell = tete;
        while(cell->getSucc())
            cell = cell->getSucc();
        Expression* exp = dynamic_cast<Expression*>(elt);  //Si on enfile une expression
        if(exp)
        {
            taille += exp->longueur();
            cell->setSucc(exp->tete); //On la concatene
        }
        else
        {
            cell->setSucc(new Cellule(elt->clone()));
            ++taille;
        }
    }
}

Donnee* Expression::defiler()
{
    if(taille>0)
    {
        Cellule* cell = tete;
        tete = cell->getSucc();
        Donnee* data = cell->getContent()->clone();
        cell->~Cellule();
        --taille;
        return data;
    }
    else
        throw CalculException("Expression vide.");
}
