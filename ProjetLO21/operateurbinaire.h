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


    /*! \fn OperateurBinaire::Calculer
     * \brief Fonction virtuelle herite d'operateur. Operations + - * / Modulo et Puissance
     *
     * La fonction calculer est la meme pour tout les operateurs binaires, mettant ainsi en commun le processus de dépilement et d'identification des données.
     * Au sein de la fonction Calculer, un switch sur typeOperateur permet d'adapter le calcul au cas desire.
     *
     * Les operateurs + - * / surcharges avec les classes Entier, Reel, Rationnel et complexe sont utilises pour le calcul des operations unaires.
     * La bibliotheque math.h est egalement largement utilise.
     *
     * Si les données dépilées sont d'un type non acceptable pour l'operation, les données sont re-empilées dans le bon ordre, et une exception est envoyée.
     * La donnée résultat est sinon empilée.
     * Dans le cas d'une donnée dépilée étant du type expressions, l'autre donnée et l'operateur sont enfiler au début ou à la fin de l'expression, selon les cas.
     * Une attention est portee a la divison, avec envoie d'une exception dans le cas ou une division par zero est effectuee.
     */
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};




#endif // OPERATEURBINAIRE_H
