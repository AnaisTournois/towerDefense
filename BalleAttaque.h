#ifndef BalleAttaque_h
#define BalleAttaque_h

#include "Balle.h"

using namespace std;

class BalleAttaque : public Balle {

public:
    BalleAttaque(Tour* tourLanceuse, int puissance, const Point& position = 0.f, const float& angle = 0.f, const float& rayon = 0.3f, bool solide = true, bool mobile = true,
                     const Point& vitesse = Point(10.f, 0.f), const float& rotation = 0.f, const float& echelle = 0.f);
    
    virtual void toucherMonstre(Monstre* monstre){};
    
};

#endif // BalleAttaque_h
