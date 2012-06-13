#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "donnee.h"
#include <iostream>

class Cellule;

class Expression : public Donnee
{
private :
    Cellule* tete;

public :
    Expression(Cellule* head = 0) : tete(head) {}
    Expression(std::string str);
    bool valide() const;  //Renvoie vrai si l'expression est syntaxiquement correcte

    void enfiler_debut(Donnee* elt);
    void enfiler_fin(Donnee* elt);

    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};

#endif // EXPRESSION_H
