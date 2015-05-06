#ifndef Joueur_h
#define Joueur_h

#include <vector>

#include "Cellule.h"
#include "TourAttaque.h"
#include "TourRalentissante.h"

class Joueur {

 public:
    virtual void poserTour(Cellule* cellule, Tour* tour);
     void setPoints(int points);
     int getPoints() const;
     void setId(int id);
     int getId() const;
     void setArgent(int argent);
     int getArgent() const;

 protected:
    int argent;
    int id;
    int points;
};

#endif // Joueur_h
