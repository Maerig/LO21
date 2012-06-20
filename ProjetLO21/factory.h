#ifndef FACTORY_H
#define FACTORY_H

#include "rationnel.h"
#include "reel.h"
#include "expression.h"
#include "operateur.h"
#include "complexe.h"

/// \brief Classe tiree du design pattern factory.
/*! Elle sert a instancier tous les types de donnees dont on a besoin.
    Note : Il ne s'agit pas d'une classe abstraite. Il faudra donc toujours instancier un objet de type Factory avant de pouvoir creer des donnees. */
class Factory
{
public:
    /// \brief Cree un nouvel Entier a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouvel Entier.
    Entier* make_entier(std::string str);
    /// \brief Cree un nouveau Reel a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouvel Reel.
    Reel* make_reel(std::string str);
    /// \brief Cree un nouveau Rationnel a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouveau Rationnel.
    Rationnel* make_rationnel(std::string str);
    /// \brief Cree un nouveau Complexe a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouveau Complexe.
    Complexe* make_complexe(std::string str);
    /// \brief Recree un Complexe a partir de sa version sauvegardee.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouveau Complexe.
    Complexe* remake_complexe(std::string str);
    /// \brief Cree une nouvelle Expression a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur une nouvelle Expression.
    Expression* make_expression(std::string str);
    /// \brief Recree une Expression a partir de sa version sauvegardee.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur une nouvelle Expression.
    Expression* remake_expression(std::string str);
    /// \brief Cree un nouvel Operateur a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur un nouvel Operateur.
    Operateur* make_operateur(std::string str);
    /// \brief Cree une nouvelle Donnee a partir de la chaine de caracteres passee en argument.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur une nouvelle Donnee.
    Donnee* make(std::string str);
    /// \brief Recree une Donnee a partir de sa version sauvegardee.
    /// \param str : Chaine de caracteres a traiter.
    /// \return Entier* : Pointeur sur une nouvelle Donnee.
    Donnee* remake(std::string str);

};

#endif // FACTORY_H
