#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "donnee.h"
#include <iostream>

class Cellule;

class Expression : public Donnee
{
private :
    Cellule* tete;
    int taille;

public :
    Expression(Cellule* head = 0, int t = 0) : tete(head), taille(t) {}
    Expression(std::string str);
    int longueur() { return taille; }
    bool valide() const;  //Renvoie vrai si l'expression est syntaxiquement correcte

    void enfiler_debut(Donnee* elt);
    void enfiler_fin(Donnee* elt);
    Donnee* defiler();

    void afficher(std::ostream& f=std::cout) const;
    void afficher_contexte(std::ostream& f) const;
    Donnee* clone() const;
};

#endif // EXPRESSION_H
