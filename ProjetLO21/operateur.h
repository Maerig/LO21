#ifndef OPERATEUR_H
#define OPERATEUR_H

#include "donnee.h"
#include "entier.h"
#include "rationnel.h"
#include "reel.h"

class Operateur : public Donnee {

};

class OperateurUnaire : public Operateur {

};

class OperateurBinaire : public Operateur {

private:
    TypeOperation typeoperation;

public:

    void Calcul(Entier a, Entier b);
    void Calcul(Reel a, Reel b);

};


#endif // OPERATEUR_H
