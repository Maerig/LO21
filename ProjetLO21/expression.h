#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "donnee.h"
#include <iostream>


class Cellule;

/// \brief Type de Donnee ayant une structure de liste chainee, et contenant d'autres donnees.
/// Elle ne peut etre evaluee que par l'operation EVAL.
class Expression : public Donnee
{
private :
    /// \brief Indique la tete de la liste.
    /// Il s'agit d'une Cellule, qui est la meme classe que celle utilisee pour la pile.
    Cellule* tete;
    /// \brief Designe le nombre d'elements contenus dans la pile.
    /// Ce nombre est change dynamiquement pendant l'execution du programme.
    int taille;

public :
    /// \brief Constructeur a partir d'une cellule et d'une taille donnee.
    /// Il est utilise pour initialier une expression vide.
    /// \param head,t : Valeurs qui vont etre affectees aux attributs. On utilise en general les valeurs par defaut.
    Expression(Cellule* head = 0, int t = 0) : tete(head), taille(t) {}
    /// \brief Constructeur a partir d'une chaine de caracteres.
    /// Pour mettre cette chaine de caracteres sous la forme d'une liste chainee, le constructeur fait appel a une methode de la classe Factory.
    Expression(std::string str);
    /// \brief Getter de la classe.
    /// Comme pour la classe Pile, il renvoie la taille courante de l'Expression.
    /// \return taille : Taille courante.
    int longueur() { return taille; }
    /// \brief Renvoie vrai si l'expression est syntaxiquement correcte.
    /// Pour s'assurer qu'elle est valide, l'expresssion simule son evaluation en essayant d'empiler un a un ses elements dans une pile factice.
    bool valide() const;

    /// \brief Enfile la donnee passee en argument en tete de la liste.
    /// \param elt : Donnee a enfiler.
    void enfiler_debut(Donnee* elt);
    /// \brief Enfile la donnee passee en argument a la fin de la liste.
    /// \param elt : Donnee a enfiler.
    void enfiler_fin(Donnee* elt);
    /// \brief Defile la donnee en tete de la liste.
    /// \return Donnee* : pointeur vers la Donnee defilee.
    Donnee* defiler();

    /// \brief Affiche l'Expression.
    /// Fonction polymorphique de la classe Donnee.
    /// \param f : Flux ou l'on affiche l'Expression.
    void afficher(std::ostream& f=std::cout) const;
    /// \brief Fournit un affichage du complexe utilisable par la sauvegarde de contexte.
    /// Fonction polymorphique de la classe Donnee.
    /// \param f : Flux ou l'on affiche le complexe.
    void afficher_contexte(std::ostream& f) const;
    /// \brief Renvoie une copie de l'Expression.
    /// Fonction polymorphique de la classe Donnee.
    Donnee* clone() const;
};

#endif // EXPRESSION_H
