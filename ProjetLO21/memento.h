#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"

class CellMem
{
private :
    Pile* contenu;
    CellMem* succ;

public :
    CellMem(Pile* cont = 0,CellMem* next = 0) : contenu(cont),succ(next) {}
    Pile* getContent() const { return contenu; }
    CellMem* getSucc() const { return succ; }
};

class Memento
{
private :
    CellMem* tete;
    int taille;

public :
    Memento(CellMem* head = 0,int t = 0) : tete(head),taille (t) {}
    int longueur() { return taille; }

    void save(Pile* stack);
    Pile* restore();
};

#endif // MEMENTO_H
