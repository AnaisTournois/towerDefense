#ifndef Chemin_h
#define Chemin_h

#include <vector>
#include "Cellule.h"

class Chemin {

public:
    Chemin();
    ajouterCellule();
    
    
 private:
    std::vector<Cellule*> chemin;
    Cellule* depart;
    Cellule* arrivee;

};

#endif // Chemin_h
