#include "Cellule.h"

Cellule::Cellule(int x, int y) {
    this->x = x;
    this->y = y;
}

int Cellule::getX() const {
    return x;
}
void Cellule::setX(int x) {
    this->x = x;
}

int Cellule::getY() const {
    return y;
}
void Cellule::setY(int y) {
    this->y = y;
}
