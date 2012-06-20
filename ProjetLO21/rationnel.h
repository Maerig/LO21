#ifndef RATIONNEL_H
#define RATIONNEL_H

/**
 * \file rationnel.h
 * \brief Definition Class Rationnel et surcharge operateurs pour Rationnel
 *
 */

#include "entier.h"


class Reel;

/*! \class Rationnel rationnel.h
 * \brief Un des 3 principaux type de nombre. Corresponds a l'ensemble des Rationnel.
 *
 * Definiton de la class Rationnel.
 * Herite de la classe nombre.
 *
 * 2 attributs de type entier. Cette classe est donc fortement dependante de la classe Entier.
 *
 */
class Rationnel : public Nombre {
private :
    Entier num;
    Entier denum;


public :

    /**
     * \brief Fonction essentiel de simplification de la fraction. Appele a la fin de tout les constructeurs.
     *
     * Necessite l'utilisation de la fonction pgcd.
     * La fonction s'assure egalement que si le numerateur et le denominateur sont negatifs, la fraction devient positif. Et si la fraction est negatif, le signe est place devant le numerateur.
     */
    void simplifier();

    /**
     * \brief Constructeur basique de la class Rationnel
     * Fait appel a deux nombres qui initialisent 2 entiers.
     * Le denominateur est par defaut 1.
     * Appel a la fonction simplifier.
     */
    Rationnel(double n=0 , double d=1) : num(n),denum(d) {simplifier();}

    /**
     * \brief Constructeur basique de la class Rationnel
     * 2 entier qui initialisent le nombre rationnel.
     * Appel a la fonction simplifier.
     */
    Rationnel(Entier n,Entier d) : num(n),denum(d) {simplifier();}

    /**
     * \brief Constructeur basique de la class Rationnel
     * Un entier qui initialise le numerateur, le denominateur est naturellement place a 1.
     * Appel a la fonction simplifier.
     */
    Rationnel(Entier e): num(e),denum(1){simplifier();}

    /**
     * \brief Constructeur important de la class Rationnel
     * Permet de creer un rationnel a partir d'une donnee.
     * Un dynamic_cast est pour cela utilise, permettant de cibler le type sous-classe de Nombre qu'est exactement le parametre entre. Le bon constructeur est alors appele.
     * Si le parametre entre n'est pas ni un rationnel ni un entier, le constructeur renvoie une exception.
     */
    Rationnel(Donnee* d);

    /**
     * \brief Permet d'obtenir l'entier numerateur.
     * Utilise dans les calculs largement.
     */
    Entier getNumerateur() const {return num;}

    /**
     * \brief Permet d'obtenir l'entier denominateur.
     * Utilise dans les calculs largement.
     */
    Entier getDenumerateur() const {return denum;}

    virtual void setSign() {num.setSign();}

    void afficher(std::ostream& f=std::cout) const { num.afficher(f); f<<"/"; denum.afficher(f); }
    void afficher_contexte(std::ostream& f) const { f<<"Rationnel:"; num.afficher(f); f<<"/"; denum.afficher(f); }
    virtual Donnee* clone() const;

    /**
     * \brief cast convertisseur d'un Rationnel en float.
     * Utilise pour le passage rationnel a reel.
     */
    operator float() const {return float(num)/float(denum);}
    Rationnel& operator=(const Rationnel& n);
};


/**
 * \brief operateur + surcharge pour gerer automatiquement l'addition de 2 Rationnels.
 *
 */
Rationnel operator+( Rationnel& a,  Rationnel& b);

/**
 * \brief operateur - surcharge pour gerer automatiquement l'addition de 2 Rationnels.
 *
 */
Rationnel operator-( Rationnel& a,  Rationnel& b);

/**
 * \brief operateur * surcharge pour gerer automatiquement l'addition de 2 Rationnels.
 *
 */
Rationnel operator*( Rationnel& a,  Rationnel& b);

/**
 * \brief operateur / surcharge pour gerer automatiquement l'addition de 2 Rationnels.
 *
 */
Rationnel operator/( Rationnel& a,  Rationnel& b);


#endif // RATIONNEL_H
