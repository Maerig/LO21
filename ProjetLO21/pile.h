#ifndef PILE_H
#define PILE_H

#include "donnee.h"
#include "factory.h"

class Cellule
{
private :
    Donnee* contenu;
    Cellule* succ;

public :
    Cellule(Donnee* cont = 0,Cellule* next = 0) : contenu(cont),succ(next) {}
    Donnee* getContent() const { return contenu; }
    Cellule* getSucc() const { return succ; }
    void setSucc(Cellule* next) { succ = next; }
};

class Pile // Pile pour les donnes
{
private :
    Cellule* tete;
    int taille;

public :
    Pile(Cellule* head = 0,int t = 0) : tete(head),taille(t) {}
    int longueur() const { return taille; }

    void empiler(Donnee* elt);
    Donnee* depiler();
};

#endif // PILE_H
