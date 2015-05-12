#include "TourRalentissante.h"
#include "BalleRalentissante.h"
#include "world.h"

void TourRalentissante::tirerBalle(mia::World* monde){
    Balle* balle = new BalleRalentissante(this, 2, this->position - Point(2.f, 0.f));
    monde->createBody(balle->castElement(), 0.4f);
}
