#ifndef DONNEE_H
#define DONNEE_H

#include <string>

class Donnee {

protected :
    static bool expression;    //indique si l'oprande fait partie d'une expression
    static std::string typedonnees;      //contient le type de donn�es � utiliser (param�tres)
    static bool typecomplexe;       //indique si les donn�es � traiter sont de type complexe (param�tres)
    static std::string typeangles;   //typeangle = degres/radians (param�tres)

public :
    static std::string getTypeDonnees() { return typedonnees; }
    static bool getTypeComplexe() { return typecomplexe; }
    static std::string getTypeAngles() { return typeangles; }
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
