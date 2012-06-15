#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "operateur.h"
#include <string>
#include "reel.h"

class OperateurUnaire : public Operateur {              //TODO

public:

    //OperateurUnaire(std::string str);

    virtual void Calculer(Pile* stack)=0;
    void afficher(std::ostream& f=std::cout) const=0;
    Donnee* clone() const=0;
};



class Sinus : public OperateurUnaire {

public:
    Sinus(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Sinus();}

};


class Cosinus : public OperateurUnaire {

public:
    Cosinus(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Cosinus();}

};


class Tang : public OperateurUnaire {

public:
    Tang(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Tang();}

};


class Sinush : public OperateurUnaire {

public:
    Sinush(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Sinush();}
};


class Cosinush : public OperateurUnaire {

public:
    Cosinush(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Cosinush();}
};


class Tangh : public OperateurUnaire {

public:
    Tangh(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Tangh();}
};


class Ln : public OperateurUnaire {

public:
    Ln(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Ln();}
};


class Log : public OperateurUnaire {

public:
    Log(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Log();}
};


class Inv : public OperateurUnaire {

public:
    Inv(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Inv();}
};


class Sqrt : public OperateurUnaire {

public:
    Sqrt(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Sqrt();}
};


class Sqr : public OperateurUnaire {

public:
    Sqr(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Sqr();}
};


class Cube : public OperateurUnaire {

public:
    Cube(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Cube();}
};


class Fact : public OperateurUnaire {

public:
    Fact(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Fact();}
};



#endif // OPERATEURUNAIRE_H
