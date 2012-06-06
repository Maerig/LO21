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





#endif // DONNEE_H
