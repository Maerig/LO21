#ifndef DONNEE_H
#define DONNEE_H

#include <string>
#include <iostream>
#include <typeinfo>

enum TypeDonnee {entier, reel, rationnel};
enum TypeAngle {degre, radian};

enum TypeOperationBinaire {PLUS,MINUS,DIV,MULT,MODULO,POW};
enum TypeOperationUnaire {SINUS,COSINUS,SINUSH,COSINUSH,TANG,TANGH,LN,LOG,INV,SQRT,SQR,CUBE,FACT};      // EVAL ?

class Donnee {

protected :
    static bool expression;    //indique si l'operande fait partie d'une expression
    static TypeDonnee typedonnees;      //contient le type de données à utiliser (paramètres)
    static bool typecomplexe;       //indique si les données à traiter sont de type complexe (paramètres)
    static TypeAngle typeangles;   //typeangle = degres/radians (paramètres)

public :
    static TypeDonnee getTypeDonnees() { return typedonnees; }
    static bool getTypeComplexe() { return typecomplexe; }
    static TypeAngle getTypeAngles() { return typeangles; }

    static void setTypeDonnees(std::string type);
    static void setTypeAngle();
    static void setTypeComplexe();

    virtual void afficher(std::ostream& f=std::cout) const = 0;
    virtual Donnee* clone() const = 0;
};

class Numerique : public Donnee {

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    std::ostream& operator<<(std::ostream& f) { afficher(f); return f; }
    virtual Donnee* clone() const = 0;
};

class Nombre : public Numerique {   //Numerique non complexe

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    virtual Donnee* clone() const = 0;

};


bool fraction(std::string str);    //renvoie "vrai" si la chaîne de caractères s'apparente à une fraction



#endif // DONNEE_H
