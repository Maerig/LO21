#ifndef PILE_H
#define PILE_H

#include "donnee.h"
#include <iostream>

/// \brief Element de la Pile.
/*! Celle-ci est implementee sous la forme d'une liste chainee. */
class Cellule
{
private :
    /// \brief Une Cellule contient un pointeur vers une Donnee.
    Donnee* contenu;
    /// \brief Le deuxieme attribut de la classe Cellule permet d'acceder a son successeur.
    Cellule* succ;

public :
    /// \brief Constructeur servant a initialiser une Pile vide.
    Cellule(Donnee* cont = 0,Cellule* next = 0) : contenu(cont),succ(next) {}
    /// \brief Destructeur de la classe.
    ~Cellule() { delete contenu; }
    /// \brief Getter pour le contenu.
    Donnee* getContent() const { return contenu; }
    /// \brief Getter pour le successeur.
    Cellule* getSucc() const { return succ; }
    /// \brief Setter pour le contenu.
    void setContent(Donnee* content) { contenu = content; }
    /// \brief Setter pour le successeur.
    void setSucc(Cellule* next) { succ = next; }
};

/// \brief Pile de donnees.
class Pile
{
private :
    /// \brief Tete de la Pile.
    Cellule* tete;
    /// \brief Taille de la Pile.
    int taille;

public :
    /// \brief Constructeur.
    Pile(Cellule* head = 0,int t = 0) : tete(head),taille(t) {}
    /// \brief Destructeur.
    ~Pile() { clear(); }
    /// \brief Getter pour la taille.
    int longueur() const { return taille; }

    /// \brief Empile une Donnee sur la Pile.
    /// \param elt : Donnee quelconque.
    void empiler(Donnee* elt);
    /// \brief Depile une Donnee.
    Donnee* depiler();

    /// \brief Affiche la Pile.
    /// \param f : Flux ou l'on affiche la Pile.
    void afficher(std::ostream& f=std::cout) const;
    /// \brief Affiche la Pile de facon a ce qu'elle soit facilement exploitable par la sauvegarde de contexte.
    /// \attention Cette fonction detruit la Pile. Elle doit donc etre appelee sur un clone.
    /// \param f : Flux ou l'on effectue cet affichage.
    void affichage_inverse(std::ostream& f=std::cout);
    /// \brief Surcharge de l'operateur << pour l'affichage
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    /// \brief Renvoie une copie de la Pile.
    Pile* clone() const;

    /// \brief Supprime le premier element de la Pile
    void drop();
    /// \brief Vide la pile.
    void clear();
    /// \brief Duplique le premier element de la Pile
    void dup();
    /// \brief Effectue la somme de tous les elements de la Pile.
    /*! Ces elements sont alors detruits. */
    void sum();
    /// \brief Permute les deux premier elements de la Pile, si elle en contient assez.
    void swap();
    /// \brief Fait la moyenne des elements de la Pile.
    /*! Ces elements sont alors detruits. */
    void mean();
};

#endif // PILE_H
