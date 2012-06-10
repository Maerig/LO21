#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "operateur.h"

class OperateurBinaire: public Operateur
{

    TypeOperationBinaire typeoperation;

public:

    OperateurBinaire(TypeOperationBinaire t): typeoperation(t) {}

    void Calculer();

};

#endif // OPERATEURBINAIRE_H
