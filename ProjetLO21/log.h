#ifndef LOG_H
#define LOG_H

#include <string>
#include "donnee.h"

/// \file log.h
/// \brief Fichier contenant les fonctions servant a ecrire dans le fichier de logs.

/// \brief Fonction chargee d'ecrire dans le fichier de logs.
/// \param str : Chaine de caracteres a inscire dans les logs.
void ecrire_log(std::string str);
/// \brief Fonction qui ecrit dans le fichier de logs une chaine de caracteres accompagnee d'une Donnee.
/// \param str : Chaine de caracteres a inscire dans les logs.
/// \param data : Pointeur vers la Donne a preciser.
void ecrire_log(std::string str,Donnee* data);

#endif // LOG_H
