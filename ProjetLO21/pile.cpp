#include "pile.h"
#include "calculexception.h"
#include <iostream>

void Pile::empiler(Donnee* elt)
{
    Cellule* cell = new Cellule(elt,tete);
    tete = cell;
    ++taille;
}

Donnee* Pile::depiler()
{
    if(taille>0)
    {
        Cellule* cell = tete;
        tete = cell->getSucc();
        Donnee* data = tete->getContent();
        cell->~Cellule();
        return data;
    }
    else
        throw CalculException("Pile vide.");
}

void Pile::afficher(std::ostream& f) const
{
    int compteur = 0;
    Cellule* cell = tete;
    while(cell)
    {
        ++compteur;
        f<<compteur<<": ";
        cell->getContent()->afficher(f);
        f<<"\n";
        cell = cell->getSucc();
    }
}

void Pile::drop()
{
    Cellule* cell = tete;
    if(tete)
    {
        tete = tete->getSucc();
        cell->~Cellule();
    }
}

void Pile::clear()
{
    while(tete) drop();
}
