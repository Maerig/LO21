#ifndef DONNEE_H
#define DONNEE_H


/**
 * \file donnee.h
 * \brief Definition Class donnee, classe principale, et classes Nombres et Numeriques
 *
 */

#include <string>
#include <iostream>
#include <typeinfo>

/// \enum TypeDonnee
/// \brief defini le type de la donnee entre, parametre par l'utilisateur
enum TypeDonnee {entier, reel, rationnel};

/// \enum TypeAngle
/// \brief defini le type d'angle avec lequel on travaille, parametre par l'utilisateur
enum TypeAngle {degre, radian};

/// \enum TypeOperationBinaire
/// \brief defini le type de l'operateur binaire. Sert a la construction de l'operateurBinaire.
enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};



/*! \class Donnee donnee.h
 * \brief Principale classe, constitue les composants de la pile.
 *
 * Definiton de la class Donnee.
 * Tout element entre a la calcultrice doit etre identifie comme donnee pour que des operations puissent avoir lieu.
 *
 * Seuls attributs possedes sont static et parametrable sur l'interface de la calculatrice, donc directement par l'utilisateur. C'est ce dernier qui determine la nature de la variable entree.
 *
 * Une donnee est soit un objet numerique (un nombre appartenant a l'ensemble des complexe ou reel ou rationnel ou entier.) soit un operateur (unaire ou binaire)
 * Fonctions virtuelles pure : afficher, afficher_contexte, clone.
 */
class Donnee {

protected :
    /// \brief contient le type de données à utiliser (paramètres)
    static TypeDonnee typedonnees;
    /// \brief indique si les données à traiter sont de type complexe (paramètres)
    static bool typecomplexe;
    /// \brief typeangle = degre/radian (paramètres)
    static TypeAngle typeangles;

public :

     /// \brief Indication du type de donnee.
    static TypeDonnee getTypeDonnees() { return typedonnees; }

    /// \brief /// \brief Indication de l'utilisation du type complexe. (Oui ou non)
    static bool getTypeComplexe() { return typecomplexe; }

    /// \brief /// \brief Indication du type angle
    static TypeAngle getTypeAngles() { return typeangles; }

    /// \brief Parametrage du type de donnee a partir d'un string
    static void setTypeDonnees(std::string type);

    /// \brief Parametrage du type de donnee a partir de l'enumeration et d'un int
    static void setTypeDonnees(int i);

    /// \brief Parametrage du type d'angle a partir de Enum TypeAngle
    static void setTypeAngle(TypeAngle type) { typeangles = type; }

    /// \brief Parametrage du type d'angle a partir de Enum TypeAngle et int
    static void setTypeAngle(int i);

    /// \brief Parametrage du type Complexe (bool)
    static void setTypeComplexe(bool b) { typecomplexe = b; }

    /// \brief Affichage d'une donnee.
    virtual void afficher(std::ostream& f=std::cout) const = 0;

    virtual void afficher_contexte(std::ostream& f) const = 0;

    /// \brief Clonage d'une donnee pour la dupliquer ou autre.
    virtual Donnee* clone() const = 0;
};

/// \class Numerique donnee.h
/// \brief Une des 2 classes filles principales de donnee.
/// Une des 2 principales classes filles de la classe donnee. Une donne est soit un numerique, soit un operateur.
/// Classe servant a definir les mecanismes generaux de fonctionnement des numeriques.
class Numerique : public Donnee {

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    virtual void afficher_contexte(std::ostream& f) const = 0;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    virtual Donnee* clone() const = 0;


    /// \brief inverse le signe d'un Numerique.
    virtual void setSign() =0;

};

/// \class Nombre donnee.h
/// \brief Principal classe des numerique. Regroupe les entier, reels et rationnels.
/// Regroupe les entiers, reels et rationnels car ils sont de fonctionnement proche.
class Nombre : public Numerique {   //Numerique non complexe

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    virtual void afficher_contexte(std::ostream& f) const = 0;
    virtual Donnee* clone() const = 0;

    virtual void setSign() =0;
};


bool number(char c);

/// \brief renvoie "vrai" si la chaine de caracteres s'apparente a un nombre
/// \return "vrai" si la chaine de caracteres s'apparente a un nombre
bool number(std::string str);

/// \brief renvoie "vrai" si la chaîne de caractères s'apparente à une fraction
/// \return "vrai" si la chaîne de caractères s'apparente à une fraction
bool fraction(std::string str);    //

#endif // DONNEE_H
