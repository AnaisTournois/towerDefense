#ifndef TourRalentissante_h
#define TourRalentissante_h

#include "Tour.h"

class TourRalentissante : public Tour {
    
public:
    TourRalentissante(Point position, float angle, float rayon, bool solide, bool mobile,
         int pointsDeVie, int attaque, int defense, float frequence):
         Tour(position,angle, rayon, solide, mobile, pointsDeVie, attaque, defense, frequence){}
    
    virtual Balle* tirerBalle(){};

};

#endif // TourRalentissante_h
