#include "pile.h"
#include "calculexception.h"
#include <iostream>
#include "entier.h"
#include "reel.h"
#include "operateur.h"


void Pile::empiler(Donnee* elt)
{
    Cellule* cell = new Cellule(elt,tete);
    tete = cell;
    ++taille;
    Operateur* op = dynamic_cast<Operateur*>(elt);
    if(op)                          //Si on empile un operateur
    {
        op = dynamic_cast<Operateur*>(depiler());   //On le depile
        if(taille>=2)
           op->Calculer(this);   //Puis on effectue le calcul
        else
            throw CalculException("La pile ne contient pas suffisamment d'elements.");
    }
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

Pile* Pile::clone() const {
    if(taille == 0)
        return new Pile;
    Cellule* cell = new Cellule(tete->getContent()->clone());
    Cellule* newhead = cell;
    Cellule* next = tete->getSucc();
    while(next)
    {
        cell->setSucc(new Cellule(next->getContent()->clone()));
        next = next->getSucc();
        cell = cell->getSucc();
    }
    return new Pile(newhead,taille);
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
        throw CalculException("La pile ne contient pas suffisamment d'�l�ments.");
    else
    {
        Cellule* newhead = tete->getSucc();
        tete->setSucc(newhead->getSucc());
        newhead->setSucc(tete);
        tete = newhead;
    }
}
