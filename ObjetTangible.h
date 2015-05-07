/* 
 * File:   ObjetTangible.h
 * Author: a
 *
 * Created on 6 mai 2015, 17:14
 */

#ifndef OBJETTANGIBLE_H
#define	OBJETTANGIBLE_H

#include <vector>
#include "Point.h"

using namespace std;

class ObjetTangible {
protected:
    vector<Point*> points;

public:

    void SetPoints(vector<Point*> points) {
        this->points = points;
    }

    vector<Point*> GetPoints() const {
        return points;
    }
};


#endif	/* OBJETTANGIBLE_H */

