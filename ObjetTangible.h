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

using namespace std;

class ObjetTangible {
protected:
    vector<mia::Point> points;

public:
    ObjetTangible();
    
    ObjetTangible(vector<mia::Point> pointsObjet){
        points = pointsObjet;
    }
    
    void setPoints(vector<mia::Point> points) {
        this->points = points;
    }

    vector<mia::Point> getPoints() const {
        return points;
    }
    
    void afficherPoints() const;
    
};


#endif	/* OBJETTANGIBLE_H */

