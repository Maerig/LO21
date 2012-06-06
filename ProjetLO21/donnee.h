#ifndef DONNEE_H
#define DONNEE_H

#include <string>

enum TypeDonnee {entier, reel, rationnel};
enum TypeAngle {degre, radian};

class Donnee {

protected :
    static bool expression;    //indique si l'oprande fait partie d'une expression
    static TypeDonnee typedonnees;      //contient le type de données à utiliser (paramètres)
    static bool typecomplexe;       //indique si les données à traiter sont de type complexe (paramètres)
    static TypeAngle typeangles;   //typeangle = degres/radians (paramètres)

public :
    static TypeDonnee getTypeDonnees() { return typedonnees; }
    static bool getTypeComplexe() { return typecomplexe; }
    static TypeAngle getTypeAngles() { return typeangles; }

    static void setTypeDonnees();
    static void setTypeAngle();
    static void setTypeComplexe();


};

class Numerique : public Donnee {

};

class Nombre : public Numerique {

};

class Reel : public Nombre {
private :
    float val;

public :
    Reel(float v) : val(v) {}

};

class Entier : public Nombre {
private :
    double val;

public :
    Entier(double v) : val(v) {}

};

class Rationnel : public Nombre {
private :
    double num;
    double denum;

public :
    Rationnel(double n,double d) : num(n),denum(d) {}

};

class Complexe : public Numerique {
private :
    Nombre a;
    Nombre b;

public :
    Complexe(Nombre Re, Nombre Im) : a(Re),b(Im) {}

};



class Operateur : public Donnee {

};

class OperateurUnaire : public Operateur {

};

class OperateurBinaire : public Operateur {

};




#endif // DONNEE_H
