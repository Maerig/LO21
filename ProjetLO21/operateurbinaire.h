#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "operateur.h"

class OperateurBinaire: public Operateur
{

    TypeOperation typeoperation;

public:

    OperateurBinaire(TypeOperation t): typeoperation(t) {}

    void Calculer();


};

#endif // OPERATEURBINAIRE_H
