#ifndef BalleAttaque_h
#define BalleAttaque_h

#include "Balle.h"

using namespace std;

class BalleAttaque : public Balle {

public:
    virtual void toucherMonstre(Monstre monstre);
    
};

#endif // BalleAttaque_h
