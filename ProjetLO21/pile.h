#ifndef PILE_H
#define PILE_H

#include "donnee.h"

class CelluleD
{
private :
    Donnee* contenu;
    CelluleD* succ;

public :
    CelluleD(Donnee* cont = 0,CelluleD* next = 0) : contenu(cont),succ(next) {}
    Donnee* getContent { return Donnee; }
    CelluleD* getSucc { return succ; }
    void setSucc(CelluleD* next) { succ = next; }
};

class PileD // Pile pour les donnes
{
private :
    CelluleD* tete;
    int taille;

public :
    void empiler(Donnee* elt);
    Donnee* depiler();
    int longueur() { return taille; }
};

class PileA // Pile pour l'affichage
{

};

#endif // PILE_H
