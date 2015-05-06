#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementCombattant.h"
#include "ElementVisuel.h"

class Joueur;
class Balle;

class Tour : public ElementVisuel, public ElementCombattant {
public:

    virtual void tirerBalle() = 0;

protected:
    int prix;
    Joueur* proprietaire;
};

#endif // Tour_h
