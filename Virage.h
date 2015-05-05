#ifndef Virage_h
#define Virage_h

#include "Point.h"

class Chemin;

class Virage {


 protected:
    bool droite;

 public:


    /**
     * @element-type Chemin
     */
    Chemin *myChemin;

    /**
     * @element-type Point
     */
    Point myPoint;
};

#endif // Virage_h
