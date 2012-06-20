#ifndef COMPLEXE_H
#define COMPLEXE_H

/**
 * \file complexe.h
 * \brief Definition Class complexe et surcharge operateurs pour complexe
 *
 */

#include "donnee.h"
#include "reel.h"


/*! \class Complexe complexe.h
 * \brief Un des 3 principaux type de nombre. Corresponds a l'ensemble des entier.
 *
 * Definition de la class complexe.
 * Herite de la classe nombre.
 * Elle est constituee de deux pointeurs vers des donnee de type Nombre.
 */

class Complexe : public Numerique {
private :
    /// \brief Partie reelle du complexe.
    /// Elle pointe sur un Nombre.
    Nombre* a;
    /// \brief Partie imaginaire du complexe.
    /// Elle pointe sur un Nombre.
    Nombre* b;

public :
    /// \brief Constructeur a partir de deux Nombres.
    /// \param Re,Im : Deux pointeurs vers des Nombres.
    Complexe(Nombre* Re, Nombre* Im) : a(Re),b(Im) {}
    /// \brief Constructeur a partir de deux Donnees.
    /// \param Re,Im : Deux pointeurs vers des Donnees.
    Complexe(Donnee* Re, Donnee* Im);
    /// \brief Constructeur par defaut
    Complexe();

    /// \brief Constructeur a partir d'une seule Donnee.
    /*! On considere qu'on cree un complexe a partir d'un nombre reel. La partie imaginaire est donc initialisee a zero. */
    /// \param d : Pointeur vers une Donnee.
    Complexe(Donnee* d);

    /**
     * \brief determine si le complexe est nul (vaut zero) ou pas
     * \return TRUE si le complexe est nul.
     */
    bool CNull();


    void setSign(){a->setSign();b->setSign();}

    /**
     * \brief surcharge operateur egal
     * Permettre l'affectation Complexe-Complexe
     */
    Complexe& operator=(const Complexe& n);

    /**
     * \brief operateur + surcharge pour gerer automatiquement l'addition de 2 Complexe.
     * Necessite de reconnaitre d'abord le type sous-classe de Nombre des attributs des 2 complexes en questions. Pour ensuite les convertir et les unifier
     *
     */
    Complexe& operator+(const Complexe& n);

    /**
     * \brief operateur - surcharge pour gerer automatiquement la soustraction de 2 Complexe.
     * Necessite de reconnaitre d'abord le type sous-classe de Nombre des attributs des 2 complexes en questions. Pour ensuite les convertir et les unifier
     *
     */
    Complexe& operator-(const Complexe& n);

    /**
     * \brief operateur / surcharge pour gerer automatiquement la division de 2 Complexe.
     * Necessite de reconnaitre d'abord le type sous-classe de Nombre des attributs des 2 complexes en questions. Pour ensuite les convertir et les unifier
     *
     */
    Complexe& operator/(const Complexe& n);

    /**
     * \brief operateur * surcharge pour gerer automatiquement la multiplication de 2 Complexe.
     * Necessite de reconnaitre d'abord le type sous-classe de Nombre des attributs des 2 complexes en questions. Pour ensuite les convertir et les unifier
     *
     */
    Complexe& operator*(const Complexe& n);

    /// \brief Affiche le Complexe.
    /// Fonction polymorphique de la classe Donnee.
    /// \param f : Flux ou l'on affiche le Complexe.
    void afficher(std::ostream& f=std::cout) const;
    /// \brief Fournit un affichage du Complexe utilisable par la sauvegarde de contexte.
    /// Fonction polymorphique de la classe Donnee.
    /// \param f : Flux ou l'on affiche le Complexe.
    void afficher_contexte(std::ostream& f) const;
    /// \brief Renvoie une copie du Complexe.
    /// Fonction polymorphique de la classe Donnee.
    Donnee* clone() const;
};

/// \brief Indique si la chaine de caracteres a la forme d'un complexe bien forme.
/// \param str : Chaine de caracteres a analyser
bool complexe_like(std::string str);
/// \brief Indique si la chaine de caracteres a la forme d'un complexe sous sa forme sauvegardee.
/// \param str : Chaine de caracteres a analyser
bool saved_complexe(std::string str);

#endif // COMPLEXE_H
