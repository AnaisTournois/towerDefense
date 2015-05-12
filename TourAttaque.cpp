#include "TourAttaque.h"
#include "BalleAttaque.h"
#include "world.h"

void TourAttaque::tirerBalle(mia::World* monde){
    Balle* balle = new BalleAttaque(this, 2, this->position + Point(2.f, 0.f));
    monde->createBody(balle->castElement(), 0.4f);
}