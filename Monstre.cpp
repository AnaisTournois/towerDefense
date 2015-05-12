#include "Monstre.h"

Monstre::Monstre(
        Chemin* cheminSuivi, const Point& position, const float& angle, const float& rayon,
        bool solide, bool mobile,
        const Point& vitesse, const float& rotation, const float& echelle,
        const int pointsDeVie, const int attaque, const int defense, const float frequence):
    mia::ElementDynamique(position, angle, rayon, solide, mobile, vitesse, rotation, echelle),
    ElementCombattant(pointsDeVie, attaque, defense, frequence),
    cheminSuivi(cheminSuivi) {
    
}

void Monstre::lancer() {
    
}


void Monstre::avancerUnPas() {

}

void Monstre::attaquerTour(Tour* tour) {
}

void Monstre::mourir() {
}

Chemin* Monstre::getCheminSuivi() const {
    return cheminSuivi;
}
