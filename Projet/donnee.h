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
};

class Entier : public Nombre {
private :
    int val;
};

class Rationnel : public Nombre {
private :
    double num;
    double denum;
};

class Complexe : public Numerique {
    Nombre a;
    Nombre b;
};



class Operateur : public Donnee {

};

class OperateurUnaire : public Operateur {

};

class OperateurBinaire : public Operateur {

};

#endif // DONNEE_H
