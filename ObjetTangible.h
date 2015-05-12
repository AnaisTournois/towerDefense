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
    
};


#endif	/* OBJETTANGIBLE_H */

