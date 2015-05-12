#include "Balle.h"

Balle::Balle(Tour* tourLanceuse, int puissance, const Point& position, const float& angle, const float& rayon, bool solide, bool mobile,
                                   const Point& vitesse, const float& rotation, const float& echelle):
           mia::ElementDynamique(position, angle, rayon, solide, mobile, vitesse, rotation, echelle), 
           tourLanceuse(tourLanceuse), puissance(puissance)     
{}

ElementDynamique Balle::castElement() {
    return ElementDynamique(position, angle, rayon, solide, mobile, vitesse, rotation, echelle);
}

