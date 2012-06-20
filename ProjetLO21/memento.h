#ifndef MEMENTO_H
#define MEMENTO_H

#include "pile.h"

/// \brief Classe Cellule adaptee pour la classe Memento
/*! Elle differe de la classe Cellule dans la mesure ou son contenu ne pointe pas vers une Donnee mais vers une Pile */
/// \see Cellule
class CellMem
{
private :
    /// \brief Le contenu de CellMem est un pointeur vers une Pile.
    Pile* contenu;
    /// \brief Etat anterieur dans le Memento.
    CellMem* succ;

public :
    /// \brief Constructeur servant a initialiser une CellMem vide.
    CellMem(Pile* cont = 0,CellMem* next = 0) : contenu(cont),succ(next) {}
    /// \brief Getter pour le contenu.
    /// \return Pile* Pointeur vers un etat de la Pile.
    Pile* getContent() const { return contenu; }
    /// \brief Getter renvoyant le successeur.
    /// \return CellMem* Pointeur vers l'etat successeur dans la Pile du Memento.
    CellMem* getSucc() const { return succ; }
};


/// \brief Pile contenant des pointeurs vers des etats successifs de la Pile principale.
/*! Implementation du design pattern Memento. Cette classe est utilisee pour les fonctions annuler et retablir.*/
/// \see Pile
class Memento
{
private :
    /// \brief Pointeur vers la CellMem en haut de la Pile du Memento.
    /*! Il s'agit de l'etat de la Pile sauvegarde le plus recent */
    CellMem* tete;
    /// \brief Taille de la Pile.
    int taille;

public :
    /// \brief Constructeur servant a initialiser un Memento vide.
    Memento(CellMem* head = 0,int t = 0) : tete(head),taille (t) {}
    /// \brief Getter de la classe.
    /// \return taille : La taille de la pile.
    int longueur() { return taille; }

    /// \brief Permet de sauvegarder un etat de la Pile.
    /// Cela correspond a la methode empiler de la Pile.
    void save(Pile* stack);
    /// \brief Permet de restaurer un etat de la Pile.
    /// Cela correspond a la methode depiler de la Pile.
    Pile* restore();
    /// \brief Remet le Memento a zero.
    /// Cela correspond a la methode clear de la Pile.
    void reset();
};

#endif // MEMENTO_H
