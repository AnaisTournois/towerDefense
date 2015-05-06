#include "Cellule.h"

Cellule::Cellule(int x, int y) {
    this->getX() = x;
    this->y = y;
}

void Cellule::SetY(int y) {
    this->y = y;
}

int Cellule::GetY() const {
    return y;
}

void Cellule::SetX(int x) {
    this->x = x;
}

int Cellule::GetX() const {
    return x;
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
