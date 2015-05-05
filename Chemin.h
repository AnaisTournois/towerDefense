#ifndef Chemin_h
#define Chemin_h

#include <vector>

#include "Point.h"
#include "Virage.h"

class Monstre;

class Chemin {

 public:

    /**
     * @element-type Monstre
     */
    std::vector< Monstre* > suit;

    /**
     * @element-type Virage
     */
    Virage myVirage;

    /**
     * @element-type Virage
     */
    Virage myVirage;

    /**
     * @element-type Point
     */
    Point myPoint;

    /**
     * @element-type Point
     */
    Point myPoint;
};

#endif // Chemin_h
