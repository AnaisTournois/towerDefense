#ifndef TourRalentissante_h
#define TourRalentissante_h

#include "Tour.h"


class TourRalentissante : public Tour {
    
public:
    TourRalentissante(vector<Point> points, Point position, float angle, float rayon, bool solide, bool mobile,
         int pointsDeVie, int attaque, int defense, float frequence):
         Tour(points,position,angle, rayon, solide, mobile, pointsDeVie, attaque, defense, frequence){}
    
    virtual void tirerBalle(mia::World* monde);

};

#endif // TourRalentissante_h
