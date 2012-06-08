#ifndef DONNEE_H
#define DONNEE_H

#include <string>
#include <iostream>

enum TypeDonnee {entier, reel, rationnel};
enum TypeAngle {degre, radian};

enum TypeOperation {plus,minus};

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

    static void setTypeDonnees();
    static void setTypeAngle();
    static void setTypeComplexe();

    virtual void afficher(std::ostream& f=std::cout) const = 0;
};

class Numerique : public Donnee {

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;

};

class Nombre : public Numerique {

public :
    virtual void afficher(std::ostream& f=std::cout) const = 0;

};




#endif // DONNEE_H
