#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

#include "operateur.h"
#include <string>

class OperateurUnaire /*: public Operateur */{              //TODO

public:

    OperateurUnaire(std::string str);

    void Calculer(Pile* stack){
/*        CalculUnaire(stack);                              */
    }

/*    virtual void CalculUnaire(Pile* stack)=0;                 TODO    */
    void afficher(std::ostream& f=std::cout) const;
    Donnee* clone() const;
};



class Sinus : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Cosinus : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Tang : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Sinush : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Cosinush : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Tangh : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Ln : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Log : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Inv : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Sqrt : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Sqr : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Cube : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};


class Fact : public OperateurUnaire {

public:
    void CalculUnaire(Pile* stack);
};



#endif // OPERATEURUNAIRE_H
