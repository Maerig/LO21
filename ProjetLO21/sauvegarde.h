#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include <string>
#include "pile.h"

void sauver_contexte(std::string name, Pile *stack);
void charger_contexte(std::string name, Pile *stack);
int get_value(std::string ligne);

#endif // SAUVEGARDE_H
