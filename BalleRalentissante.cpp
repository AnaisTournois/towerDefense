#include "BalleRalentissante.h"

BalleRalentissante::BalleRalentissante(Tour* tourLanceuse, int puissance, const Point& position, const float& angle, const float& rayon, bool solide, bool mobile,
                                   const Point& vitesse, const float& rotation, const float& echelle):
           Balle(tourLanceuse, puissance, position, angle, rayon, solide, mobile, vitesse, rotation, echelle){}