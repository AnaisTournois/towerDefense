#ifndef Balle_h
#define Balle_h

#include "ElementDynamique.h"
#include "Monstre.h"
#include "Tour.h"

using namespace std;

class Balle : public ElementDynamique {
public:
    virtual void toucherMonstre(Monstre monstre) = 0;

    void setTourLanceuse(Tour* tourLanceuse) {
        this->tourLanceuse = tourLanceuse;
    }

    Tour* getTourLanceuse() const {
        return tourLanceuse;
    }

    void setPuissance(int puissance) {
        this->puissance = puissance;
    }

    int getPuissance() const {
        return puissance;
    }

    void toucheMonstre(Monstre monstre);
    
protected:
    int puissance;
    Tour* tourLanceuse;
};

#endif // Balle_h
