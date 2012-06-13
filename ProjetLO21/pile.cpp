#include "pile.h"
#include "calculexception.h"
#include <iostream>
#include "entier.h"
#include "reel.h"


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
        Donnee* data = cell->getContent()->clone();
        cell->~Cellule();
        --taille;
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
        --taille;
    }
}

void Pile::clear()
{
    while(tete) drop();
}

void Pile::dup()
{
    if(taille>=1)
    {
        Cellule* cell = new Cellule(tete->getContent()->clone(),tete);
        tete = cell;
        ++taille;
    }
    else
        throw CalculException("Pile vide.");
}

void Pile::sum()
{
    Reel somme(0);
    Cellule* cell = tete;
    while(cell)
    {
        somme = 0;  //todo
        cell = cell->getSucc();
    }
    empiler(new Entier((double)somme.getVal()));
}

void Pile::swap()
{
    if(taille<2)
        throw CalculException("La pile ne contient pas suffisamment d'éléments.");
    else
    {
        Cellule* newhead = tete->getSucc();
        tete->setSucc(newhead->getSucc());
        newhead->setSucc(tete);
        tete = newhead;
    }
}
