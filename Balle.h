#ifndef Balle_h
#define Balle_h

#include "ElementDynamique.h"
//#include "Tour.h"

using namespace std;

class Monstre;
class Tour;

class Balle : public mia::ElementDynamique{

protected:
    int puissance;
    Tour* tourLanceuse;

public:
    Balle(Tour* tourLanceuse, int puissance, const Point& position = 0.f, const float& angle = 0.f, const float& rayon = 0.f, bool solide = true, bool mobile = true,
                     const Point& vitesse = 0.f, const float& rotation = 0.f, const float& echelle = 0.f);
    
    ElementDynamique castElement();
    
    virtual void toucherMonstre(Monstre* monstre) {};
    
    Tour* getTourLanceuse() const {
        return tourLanceuse;
    }

    int getPuissance() const {
        return puissance;
    }
};

#endif // Balle_h
