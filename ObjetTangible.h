/* 
 * File:   ObjetTangible.h
 * Author: a
 *
 * Created on 6 mai 2015, 17:14
 */

#ifndef OBJETTANGIBLE_H
#define	OBJETTANGIBLE_H

#include <vector>
#include <iostream>
#include "Point.h"
#include "ElementVisuel.h"


using namespace std;

namespace mia{
    class World;
} 

class ObjetTangible :  public ElementVisuel {
protected:
    vector<mia::Point> points;

public:
    ObjetTangible(vector<mia::Point> pointsObjet, Point position, float angle, float rayon, bool solide, bool mobile):
    points(pointsObjet), ElementVisuel(position,angle, rayon, solide, mobile){}
    
    void setPoints(vector<mia::Point> points) {
        this->points = points;
    }

    vector<mia::Point> getPoints() const {
        return points;
    }
    
    void afficherPoints() const;
    
    virtual void tirerBalle(mia::World* monde){};
    
};


#endif	/* OBJETTANGIBLE_H */

