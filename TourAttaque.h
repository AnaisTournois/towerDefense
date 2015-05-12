#ifndef TourAttaque_h
#define TourAttaque_h

#include "Tour.h"
#include "Balle.h"

class Balle;

class TourAttaque : public Tour {

public:
    TourAttaque(vector<Point> points, Point position, float angle, float rayon, bool solide, bool mobile,
         int pointsDeVie, int attaque, int defense, float frequence):
         Tour(points, position,angle, rayon, solide, mobile, pointsDeVie, attaque, defense, frequence){}
    
    virtual Balle* tirerBalle(){};

};

#endif // TourAttaque_h
