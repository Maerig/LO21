#include "pile.h"
#include "calculexception.h"

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
        delete cell;
        return data;
    }
    else
        throw CalculException("Pile vide.");
}
