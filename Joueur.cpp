#include "Joueur.h"

Joueur::Joueur(int id, int argent, int points) :
id(id), argent(argent), points(points) {
}

Joueur::~Joueur() {
    for (int i = 0; i < tours.size(); i++) {
        delete tours[i];
        tours[i] = 0;
    }
}

void Joueur::poserTour(Point* point, Tour* tour) {
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
