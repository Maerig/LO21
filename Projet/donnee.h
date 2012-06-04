#ifndef DONNEE_H
#define DONNEE_H

class Donnee {

protected :
    bool expression;    //indique si l'opérande fait partie d'une expression

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
