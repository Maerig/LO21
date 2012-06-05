#ifndef PILE_H
#define PILE_H

#include "donnee.h"
#include "factory.h"

class CelluleD
{
private :
    Donnee* contenu;
    CelluleD* succ;

public :
    CelluleD(Donnee* cont = 0,CelluleD* next = 0) : contenu(cont),succ(next) {}
    Donnee* getContent() { return contenu; }
    CelluleD* getSucc() const { return succ; }
    void setSucc(CelluleD* next) { succ = next; }
};

class PileD // Pile pour les donnes
{
private :
    CelluleD* tete;
    int taille;

public :
    PileD(CelluleD* head = 0,int t = 0) : tete(head),taille(t) {}
    int longueur() const { return taille; }

    void empiler(Donnee* elt);
    Donnee* depiler();
};

class PileA // Pile pour l'affichage
{

};

#endif // PILE_H