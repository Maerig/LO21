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

/*! \class OperateurBinaire operateurbinaire.h
 * \brief classe des operateurs binaire + - * / Modulo et Puissance
 *
 * Definiton de la class OperateurBinaire. Elle concerne les operateurs + - * / Modulo et Puissance entree dans la calculatrice.
 * Ces operateurs sont introduits dans la pile sous la forme d'objets operateurBinaire, se différenciant par l'attribut typeOperation.
 *
 */
class OperateurBinaire: public Operateur
{

    TypeOperationBinaire typeoperation;

public:
    /**
     * \brief Constructeur de la class OperateurBinaire. Il suffit de donner le type de l'operation en argument, a partir de l'enum TypeOperationBinaire dans donnee.h
     */
    OperateurBinaire(TypeOperationBinaire t): typeoperation(t) {}

    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};




#endif // OPERATEURBINAIRE_H
