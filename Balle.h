#ifndef Balle_h
#define Balle_h

//#include "ElementDynamique.h"
#include "Monstre.h"
#include "Tour.h"

using namespace std;

class Balle : public ElementDynamique {

protected:
    int puissance;
    Tour* tourLanceuse;

public:
    virtual void toucherMonstre(Monstre monstre) = 0;

    Tour* getTourLanceuse() const {
        return tourLanceuse;
    }

    int getPuissance() const {
        return puissance;
    }
};

#endif // Balle_h
