#include "memento.h"
#include "calculexception.h"

void Memento::save(Pile* stack)
{
    tete = new CellMem(stack->clone(),tete);
    ++taille;
}

Pile* Memento::restore()
{
    if(taille>0)
    {
        CellMem* cell = tete;
        tete = cell->getSucc();
        Pile* newstack = cell->getContent()->clone();
        cell->~CellMem();
        --taille;
        return newstack;
    }
        throw CalculException("Impossible d'annuler.");
}

void Memento::reset()
{
    while(tete) restore();
}
