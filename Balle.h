#ifndef Balle_h
#define Balle_h

#include "ElementDynamique.h"
#include "Monstre.h"

class Balle : public ElementDynamique {

 public:

    virtual void toucherMonstre(Monstre monstre) = 0;


 protected:
    int puissance;

};

#endif // Balle_h
