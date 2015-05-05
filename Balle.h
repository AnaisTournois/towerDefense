#ifndef Balle_h
#define Balle_h

#include "BalleAttaque.h"
#include "ElementDynamique.h"
#include "Monstre.h"

class Tour;

class Balle : public ElementDynamique, public BalleAttaque {

 public:

    virtual void toucherMonstre(Monstre monstre)  = 0;


 protected:
    int puissance;

 public:

    Tour *tire;

    Monstre ** touche;
};

#endif // Balle_h
