#ifndef TourAttaque_h
#define TourAttaque_h

#include "Tour.h"

class TourAttaque : public Tour {

public:
    virtual Balle* tirerBalle();

};

#endif // TourAttaque_h
