#ifndef ENTIER_H
#define ENTIER_H

/**
 * \file entier.h
 * \brief Definition Class entier et surcharge operateurs pour entiers
 *
 */
#include "donnee.h"
#include "calculexception.h"

/*! \class Entier entier.h
 * \brief Un des 3 principaux type de nombre. Corresponds a l'ensemble des entier.
 *
 * Definiton de la class Entier.
 * Herite de la classe nombre.
 * Attribut unique et principal : un long int, ce qui permet de n'avoir que des nombres entier en attribut, simplifiant considerablement la tache dans pas mal d'operations entre complexe et rationnels ayant des membres entiers.
 * Le type long int, a la difference de double, permet d'assurer que l'attribut val d'Entier ne soit pas un reel, ce qui serai nefaste a la class Entier.
 *
 */
class Entier : public Nombre {
private :
    long int val;

public :
    /**
     * \brief Unique constructeur de la class Entier.
     * Le type pris en parametre est double, la conversion implicite est effectue a l'initialisation de l'attribut.
     */
    Entier(double v=0) : val(v) {}

    /**
     * \brief Permet d'obtenir la valeur de val.
     * Utilise pour la gestion des operations avec rationnels, puisque ceux-ci sont constitues d'entier.
     */
    double getVal() const {return val;}

    /**
     * \brief Permet de modifier la valeur de val.
     * Utilise pour la gestion des operations avec rationnels, puisque ceux-ci sont constitues d'entier.
     */
    void setVal(double v){val=v;}

    virtual void setSign() {val=(-val);}

    void afficher(std::ostream& f=std::cout) const { f<<val; }
    void afficher_contexte(std::ostream& f) const { f<<"Entier:"<<val; }
    Donnee* clone() const;

    /**
     * \brief cast convertisseur d'un Entier en float.
     * Utilise pour le passage d'un Entier a un reel. Utilise surtout pour le passage d'un rationnel (compose de 2 entier) a un reel.
     */
    operator float() const {return float(val);}

    Entier& operator=(const Entier& n);
};

/**
 * \brief operateur + surcharge pour gerer automatiquement l'addition de 2 Entiers.
 * Relativement simple puisque operation sur 2 attributs du meme type long int.
 */
Entier operator+( Entier  &a,  Entier  &b);

/**
 * \brief operateur - surcharge pour gerer automatiquement la soustraction de 2 Entiers.
 * Relativement simple puisque operation sur 2 attributs du meme type long int.
 */
Entier operator-( Entier  &a,  Entier  &b);

/**
 * \brief operateur * surcharge pour gerer automatiquement la multiplication de 2 Entiers.
 * Relativement simple puisque operation sur 2 attributs du meme type long int.
 */
Entier operator*( Entier  &a,  Entier  &b);

/**
 * \brief operateur / surcharge pour gerer automatiquement la division entre 2 Entiers.
 * Relativement simple puisque operation sur 2 attributs du meme type long int.
 */
Entier operator/( Entier  &a,  Entier  &b);

/**
 * \brief operateur % surcharge pour gerer automatiquement le calcul de modulo entre 2 Entiers.
 * Relativement simple puisque operation sur 2 attributs du meme type long int.
 */
Entier operator%( Entier  &a,  Entier  &b);




#endif // ENTIER_H
