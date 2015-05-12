/* 
 * File:   DetecteurObjetTangible.h
 * Author: a
 *
 * Created on 11 mai 2015, 09:03
 */

#ifndef DETECTEUROBJETTANGIBLE_H
#define	DETECTEUROBJETTANGIBLE_H

#include <iostream>
#include <vector>

#include "frame.h"
#include "Point.h"

#include "ObjetTangible.h"
#include "TourAttaque.h"
#include "TourRalentissante.h"

using namespace std;

class DetecteurObjetTangible{
private:
    
public:
    ObjetTangible* detecterObjetTangible(std::vector<mia::Point> points);
    
                
    
};

#endif	/* DETECTEUROBJETTANGIBLE_H */

