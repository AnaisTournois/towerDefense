#ifndef Joueur_h
#define Joueur_h

#include <vector>

#include "Cellule.h"
#include "Tour.h"

class Tour;

class Joueur {
public:
    Joueur(int id, int argent = 10, int points = 0);
    ~Joueur();
    void poserTour(Point* point, Tour* tour);
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
    vector<Tour*> tours;
};

#endif // Joueur_h
