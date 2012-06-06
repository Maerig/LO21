#include "pile.h"
#include "calculexception.h"

void PileD::empiler(Donnee* elt)
{
    CelluleD* cell = new CelluleD(elt,tete);
    tete = cell;
    ++taille;
}

Donnee* PileD::depiler()
{
    if(taille>0)
    {
        CelluleD* cell = tete;
        tete = cell->getSucc();
        Donnee* data = tete->getContent();
        delete cell;
        return data;
    }
    else
        throw CalculException("Pile vide.");
}


void PileA::empiler(Donnee* elt)
{
    CelluleA* cell = new CelluleA(elt,tete);
    tete = cell;
    ++taille;
}

Donnee* PileA::depiler()
{
    CelluleA* cell = tete;
    tete = cell->getSucc();
    Donnee* data = tete->getContent();
    delete cell;
    return data;
}
