#ifndef Chemin_h
#define Chemin_h

#include <vector>
#include "Cellule.h"

class Chemin {

public:
    Chemin();
    ajouterCellule();

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
    
    
 private:
    std::vector<Cellule*> chemin;
    Cellule* depart;
    Cellule* arrivee;

};

#endif // Chemin_h
