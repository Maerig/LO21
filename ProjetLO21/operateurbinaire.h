#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

/**
 * \file operateurbinaire.h
 * \brief Definition Class OperateurBinaire.
 *
 *
 */


#include "operateur.h"
#include <string>

/*! \class OperateurBinaire
 * \brief classe representant les operateurs binaire + - * / Modulo et Puissance
 *
 * Definiton de la class OperateurBinaire. Elle concerne les operateurs + - * / Modulo et Puissance.
 * Ces operateurs sont introduits dans la pile sous la forme d'objets operateurBinaire, se différenciant par l'attribut typeOperation.
 *
 */
class OperateurBinaire: public Operateur
{

    TypeOperationBinaire typeoperation;

public:

    OperateurBinaire(TypeOperationBinaire t): typeoperation(t) {}

    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};




#endif // OPERATEURBINAIRE_H
