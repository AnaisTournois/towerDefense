#ifndef BalleRalentissante_h
#define BalleRalentissante_h

#include "Balle.h"

using namespace std;

class BalleRalentissante : public Balle {

public:
    BalleRalentissante(Tour* tourLanceuse);
    virtual void toucherMonstre(Monstre* monstre);
    
};

#endif // BalleRalentissante_h
