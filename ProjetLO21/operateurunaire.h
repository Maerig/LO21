#ifndef OPERATEURUNAIRE_H
#define OPERATEURUNAIRE_H

/**
 * \file operateurunaire.h
 * \brief Definition Class OperateurBinaire (herite d'Operateur) et de ses classes filles (sinus, cosinus, SQR ...)
 *
 * OperateurUnaire gère le fonctionnement des Données étant des opérateurs, plus spécifiquement étant des operateurs unaires.
 * Les différentes operations unaires sont les différentes classes filles de la classe OperateurUnaire.
 * Selon le type de l'operateur, le calcul est different. Toute les fonction calculer des operateurs unaires ont ce fonctionnement:
 * Depilement du premier element de la pile. Repérage du type de l'element. Re-empilement de l'element et lancement d'exception si le type de la donnee n'accepte pas ce type d'operation. Sinon conversion si besoin, calcul et mise du resultat dans une nouvelle donnee, empilement de la donnee resultante
 *
 */


#include "operateur.h"
#include <string>
#include "reel.h"

/*! \class OperateurUnaire operateurunaire.h
 * \brief Classe fille de la classe Operateur. Classe mère des operateurs unaire. Equivalent de la classe OperateurBinaire, bien que le fonctionnement soit différent.
 *
 * OperateurUnaire sert à regrouper tous les operateurs unaires sous une même classe mere, dans un souci d'organisation et de compréhension du code source.
 * Selon le type de l'operateur, le calcul est different. Toute les fonction calculer des operateurs unaires ont ce fonctionnement:
 * Depilement du premier element de la pile. Repérage du type de l'element. Re-empilement de l'element et lancement d'exception si le type de la donnee n'accepte pas ce type d'operation. Sinon conversion si besoin, calcul et mise du resultat dans une nouvelle donnee, empilement de la donnee resultante
 */
class OperateurUnaire : public Operateur {

public:
    virtual void Calculer(Pile* stack)=0;
    void afficher(std::ostream& f=std::cout) const=0;
    Donnee* clone() const=0;
};


/*! \class Sinus operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du sinus d'un nombre.
 *
 */
class Sinus : public OperateurUnaire {

public:
    Sinus(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIN";}
    Donnee* clone() const{return new Sinus();}

};

/*! \class Cosinus operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du cosinus d'un nombre.
 *
 */
class Cosinus : public OperateurUnaire {

public:
    Cosinus(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"COS";}
    Donnee* clone() const{return new Cosinus();}

};

/*! \class Tang operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Tang d'un nombre.
 *
 */
class Tang : public OperateurUnaire {

public:
    Tang(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"TAN";}
    Donnee* clone() const{return new Tang();}

};

/*! \class Sinush operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Sinush d'un nombre.
 *
 */
class Sinush : public OperateurUnaire {

public:
    Sinush(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SINH";}
    Donnee* clone() const{return new Sinush();}
};

/*! \class Cosinush operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Cosinush d'un nombre.
 *
 */
class Cosinush : public OperateurUnaire {

public:
    Cosinush(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"COSH";}
    Donnee* clone() const{return new Cosinush();}
};

/*! \class Tangh operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Tangh d'un nombre.
 *
 */
class Tangh : public OperateurUnaire {

public:
    Tangh(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"TANH";}
    Donnee* clone() const{return new Tangh();}
};

/*! \class Ln operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Ln d'un nombre.
 *
 */
class Ln : public OperateurUnaire {

public:
    Ln(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"LN";}
    Donnee* clone() const{return new Ln();}
};

/*! \class Log operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Log d'un nombre.
 *
 */
class Log : public OperateurUnaire {

public:
    Log(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"LOG";}
    Donnee* clone() const{return new Log();}
};

/*! \class Inv operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Inv d'un nombre.
 *
 */
class Inv : public OperateurUnaire {

public:
    Inv(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"INV";}
    Donnee* clone() const{return new Inv();}
};

/*! \class Sqrt operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Sqrt d'un nombre.
 *
 */
class Sqrt : public OperateurUnaire {

public:
    Sqrt(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SQRT";}
    Donnee* clone() const{return new Sqrt();}
};

/*! \class Sqr operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Sqr d'un nombre.
 *
 */
class Sqr : public OperateurUnaire {

public:
    Sqr(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SQR";}
    Donnee* clone() const{return new Sqr();}
};

/*! \class Cube operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Cube d'un nombre.
 *
 */
class Cube : public OperateurUnaire {

public:
    Cube(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"CUBE";}
    Donnee* clone() const{return new Cube();}
};

/*! \class Fact operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Fact d'un nombre.
 *
 */
class Fact : public OperateurUnaire {

public:
    Fact(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"!";}
    Donnee* clone() const{return new Fact();}
};

/*! \class Sign operateurunaire.h
 * \brief Classe fille de OperateurUnaire. Relatif au calcul du Sign d'un nombre.
 *
 */
class Sign : public OperateurUnaire {

public:
    Sign(){}
    void Calculer(Pile* stack);
    void afficher(std::ostream& f=std::cout) const{f<<"SIGN";}
    Donnee* clone() const{return new Sign();}
};


#endif // OPERATEURUNAIRE_H
