#include "pile.h"

void PileD::empiler(Donnee* elt)
{
    CelluleD* cell = new CelluleD(elt,tete);
    tete = cell;
    ++taille;
}

Donnee* PileD::depiler()
{
    CelluleD* cell = tete;
    tete = cell->succ;
    data = cell->contenu;
    delete cell;
    return data;
}
