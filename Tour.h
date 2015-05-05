#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementCombattant.h"
#include "ElementVisuel.h"

class Joueur;
class Balle;

class Tour : public ElementVisuel, public ElementVisuel, public ElementCombattant {

 public:

    virtual void tirerBalle()  = 0;

 public:
    int prix;

 public:

    Joueur *appartient à;

    /**
     * @element-type Balle
     */
    std::vector< Balle* > tire;
};

#endif // Tour_h
