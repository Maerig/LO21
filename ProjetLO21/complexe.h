#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "donnee.h"
#include "reel.h"

class Complexe : public Numerique {
private :
    Nombre* a;
    Nombre* b;

public :
    Complexe(Nombre* Re, Nombre* Im) : a(Re),b(Im) {}
    Complexe(Donnee* Re, Donnee* Im);
    Complexe();

    Complexe(Donnee* d);

    bool CNull();


    void setSign(){a->setSign();b->setSign();}

    Complexe& operator=(const Complexe& n);

    Complexe& operator+(const Complexe& n);
    Complexe& operator-(const Complexe& n);
    Complexe& operator/(const Complexe& n);
    Complexe& operator*(const Complexe& n);

    void afficher(std::ostream& f=std::cout) const;
    void afficher_contexte(std::ostream& f) const;
    Donnee* clone() const;
};

bool complexe_like(std::string str);
bool saved_complexe(std::string str);

#endif // COMPLEXE_H
