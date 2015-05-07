#include "Joueur.h"

void Joueur::poserTour(Cellule* cellule, Tour* tour) {
}

void Joueur::setPoints(int points) {
    this->points = points;
}

int Joueur::getPoints() const {
    return points;
}

void Joueur::setId(int id) {
    this->id = id;
}

int Joueur::getId() const {
    return id;
}

void Joueur::setArgent(int argent) {
    this->argent = argent;
}

int Joueur::getArgent() const {
    return argent;
}
