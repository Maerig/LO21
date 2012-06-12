#ifndef PILE_H
#define PILE_H

#include "donnee.h"
#include <iostream>

class Cellule
{
private :
    Donnee* contenu;
    Cellule* succ;

public :
    Cellule(Donnee* cont = 0,Cellule* next = 0) : contenu(cont),succ(next) {}
    ~Cellule() { delete contenu; }
    Donnee* getContent() const { return contenu; }
    Cellule* getSucc() const { return succ; }
    void setContent(Donnee* content) { contenu = content; }
    void setSucc(Cellule* next) { succ = next; }
};

class Pile
{
private :
    Cellule* tete;
    int taille;

public :
    Pile(Cellule* head = 0,int t = 0) : tete(head),taille(t) {}
    ~Pile() { clear(); }
    int longueur() const { return taille; }

    void empiler(Donnee* elt);
    Donnee* depiler();
    void afficher(std::ostream& f=std::cout) const;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }

    void drop();
    void clear();
    void dup();
    void sum();
    void swap();
};

#endif // PILE_H
