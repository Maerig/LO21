#ifndef REEL_H
#define REEL_H


/**
 * \file reel.h
 * \brief Definition Class reel et surcharge operateurs pour reels
 *
 */
#include "rationnel.h"

/*! \class Reel reel.h
 * \brief Un des 3 principaux type de nombre. Corresponds a l'ensemble des Reels.
 *
 * Definiton de la class Reel.
 * Herite de la classe nombre.
 * Attribut unique et principal : un float, choix evident: nombre a virgules accepte, type correspondant tout a fait a l'ensemble des reels.
 *
 */
class Reel : public Nombre {
private :
    float val;

public :
    /**
     * \brief Constructeur basique de la class Reel
     *
     */
    Reel(float v=0) : val(v) {}

    /**
     * \brief Constructeur secondaire de la class Reel
     * Permet de creer un reel a partir d'un Entier.
     */
    Reel(Entier e);

    /**
     * \brief Constructeur secondaire de la class Reel
     * Permet de creer un reel a partir d'un Rationnel.
     */
    Reel(Rationnel r);

    /**
     * \brief Constructeur important de la class Reel
     * Permet de creer un reel a partir d'une donnee.
     * Un dynamic_cast est pour cela utilise, permettant de cibler le type sous-classe de Nombre qu'est exactement le parametre entre. Le bon constructeur est alors appele.
     * Si le parametre entre n'est pas un Nombre, le constructeur renvoie une exception.
     */
    Reel(Donnee* d);

    /**
     * \brief Permet d'obtenir la valeur de val.
     * Utilise pour la gestion des operations avec rationnels, puisque ceux-ci sont constitues d'entier.
     */
    float getVal() const {return val;}

    virtual void setSign() {val=(-val);}

    void afficher(std::ostream& f=std::cout) const { f<<val; }
    void afficher_contexte(std::ostream& f) const { f<<"Reel:"<<val; }
    virtual Donnee* clone() const;

    /**
     * \brief cast convertisseur d'un Reel en float.
     * Utilise pour les calculs.
     */
    operator float() const {return val;}

    /**
     * \brief surcharge operateur egal
     * Permettre l'affectation Reel-Reel
     */
    Reel& operator=(const Reel& n);
};

/**
 * \brief operateur + surcharge pour gerer automatiquement l'addition de 2 Reel.
 * Relativement simple puisque operation sur 2 attributs du meme type float.
 */
Reel operator+( Reel& a,  Reel& b);

/**
 * \brief operateur - surcharge pour gerer automatiquement la soustraction de 2 Reel.
 * Relativement simple puisque operation sur 2 attributs du meme type float.
 */
Reel operator-( Reel& a,  Reel& b);

/**
 * \brief operateur * surcharge pour gerer automatiquement la multiplication de 2 Reel.
 * Relativement simple puisque operation sur 2 attributs du meme type float.
 */
Reel operator*( Reel& a,  Reel& b);

/**
 * \brief operateur / surcharge pour gerer automatiquement la division de 2 Reel.
 * Relativement simple puisque operation sur 2 attributs du meme type float.
 */
Reel operator/( Reel& a,  Reel& b);









#endif // REEL_H
