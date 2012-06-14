#ifndef OPERATEURBINAIRE_H
#define OPERATEURBINAIRE_H

#include "operateur.h"
#include <string>

class OperateurBinaire: public Operateur
{

    TypeOperationBinaire typeoperation;

public:

    OperateurBinaire(TypeOperationBinaire t): typeoperation(t) {}
    //OperateurBinaire(std::string str);

    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};




#endif // OPERATEURBINAIRE_H
