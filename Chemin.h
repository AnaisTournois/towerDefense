#ifndef Chemin_h
#define Chemin_h

#include <vector>
#include "Cellule.h"

using namespace std;

class Chemin {
    
 private:
    std::vector<Cellule*> chemin;
    Cellule* depart;
    Cellule* arrivee;

public:
    Chemin();
    void ajouterCellule(Cellule* celulle);

    void setArrivee(Cellule* arrivee) {
        this->arrivee = arrivee;
    }

    Cellule* getArrivee() const {
        return arrivee;
    }

    void setDepart(Cellule* depart) {
        this->depart = depart;
    }

    Cellule* getDepart() const {
        return depart;
    }

    void setChemin(std::vector<Cellule*> chemin) {
        this->chemin = chemin;
    }

    std::vector<Cellule*> getChemin() const {
        return chemin;
    }
    

};

#endif // Chemin_h
