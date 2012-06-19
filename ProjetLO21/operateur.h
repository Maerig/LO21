#ifndef OPERATEUR_H
#define OPERATEUR_H

/**
 * \file operateur.h
 * \brief Definition Class Operateur
 *
 * Une des 2 principales classes filles de la classe donnee. Une donne est soit un numerique, soit un operateur.
 */

#include "pile.h"
#include "reel.h"
#include "calculexception.h"
#include "complexe.h"
#include "expression.h"

/*! \class Operateur operateur.h
 * \brief class mere de tout les operateurs
 *
 * Classe servant a definir les mecanismes generaux de fonctionnement des operateurs.
 * La methode Calculer est la principale specification des objets instances de sous-classe d'operateur. Elle differe entre chaque operateur, selon l'operation desire.
 *
 */
class Operateur : public Donnee {


public :
    /**
    * \brief Fonction Calculer virtuelle pure dans operateur. Fonction principale de la classe et de toute les classes filles.
    *
    * Tout operateur peut faire appel a la fonction calculer, mais celle-ci differe de facon importante d'un operateur a un autre, et surtout d'un operateur binaire a un operateur unaire.
    */
    virtual void Calculer(Pile* stack)=0;
    virtual void afficher(std::ostream& f=std::cout) const = 0;
    void afficher_contexte(std::ostream &f) const { f<<"Operateur:";afficher(f); }
    virtual Donnee* clone() const = 0;
};


/**
* \brief Fonction permettant de reconnaitre si un string entree sur la calculatrice correspond a un operateur.
*
* Plus precisement, cette fonction verifie si le string ne correspond pas un nombre, dans lequel des cas le string devrait alors etre un operateur. Si le string n'est pas un nombre, la fonction renvoie 1 soit un oui.
*/
bool operateur_like(std::string str);




#endif // OPERATEUR_H
