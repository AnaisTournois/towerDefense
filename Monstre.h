#ifndef Monstre_h
#define Monstre_h

#include <vector>

#include "ElementCombattant.h"
#include "ElementDynamique.h"

class Vague;
class Chemin;
class Balle;

class Monstre : public ElementDynamique, public ElementCombattant {

 public:

    virtual void attaquerTour();

    virtual void mourir();

 public:

    /**
     * @element-type Vague
     */
    Vague *myVague;

    /**
     * @element-type Vague
     */
    std::vector< Vague* > est composée de;

    Chemin *suit;

    /**
     * @element-type Balle
     */
    std::vector< Balle* > touche;
};

#endif // Monstre_h
