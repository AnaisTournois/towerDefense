#ifndef Joueur_h
#define Joueur_h

#include <vector>

#include "Point.h"
#include "TourAttaque.h"
#include "TourRalentissante.h"

class Tour;
class Jeu;

class Joueur {

 public:

    virtual poserTour(Point point, TourAttaque tour);

    virtual void poserTour(Point point, TourRalentissante tour);

 public:
    int argent;

 protected:
    int id;
    int points;

 public:

    /**
     * @element-type Tour
     */
    std::vector< Tour* > appartient à;

    Jeu *participe à;
};

#endif // Joueur_h
