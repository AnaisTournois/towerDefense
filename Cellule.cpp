#include "Cellule.h"

Cellule::Cellule(int x, int y) {
    this->getX() = x;
    this->y = y;
}

int Cellule::getX() {
    return x;
}
int Cellule::setX(int x) {
    this->x = x;
}

int Cellule::getY() {
    return y;
}
int Cellule::setY(int y) {
    this->y = y;
}
