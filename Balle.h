#ifndef Balle_h
#define Balle_h

#include "ElementDynamique.h"
#include "Monstre.h"
#include "Tour.h"

class Balle : public ElementDynamique{
    //Attributs
 public:
    virtual void toucherMonstre(Monstre monstre)  = 0;
    
 protected:
    int puissance;
    Tour* tourLanceuse;
};

#endif // Balle_h
