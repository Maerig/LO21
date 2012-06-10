#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "operateur.h"

class OperateurUnaire : public Operateur {


    TypeOperationUnaire typeoperation;

public:

    OperateurUnaire(TypeOperationUnaire t): typeoperation(t) {}

    void Calculer();

};

#endif // OPERATEURUNAIRE_H
