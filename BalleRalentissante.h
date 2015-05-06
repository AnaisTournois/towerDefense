#ifndef BalleRalentissante_h
#define BalleRalentissante_h

#include "Balle.h"


class BalleRalentissante : public Balle {

public:
    virtual void toucherMonstre(Monstre monstre);
    
};

#endif // BalleRalentissante_h
