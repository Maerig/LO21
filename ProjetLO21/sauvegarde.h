#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <string>
#include "pile.h"

/// \file sauvegarde.h
/// \brief Contient les fonctions utilisees pour la sauvegarde du contexte

/// \brief Sauvegarde dans un fichier les parametres et la Pile.
/// \param name : Nom du fichier
/// \param stack : Pile a sauvegarder
void sauver_contexte(std::string name, Pile *stack);
/// \brief Charge a partir un fichier les parametres et le contenu de la Pile.
/// \param name : Nom du fichier
/// \param stack : Pile dans laquelle charger sauvegarder
void charger_contexte(std::string name, Pile *stack);
/// \brief Renvoie la valeur attribuee a un parametre dans le fichier de sauvegarde de contexte.
/// \param ligne : Ligne du fichier.
int get_value(std::string ligne);

#endif // SAUVEGARDE_H
