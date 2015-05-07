#include "Monstre.h"


void Monstre::avancerUnPas() {

}

void Monstre::attaquerTour() {
}

void Monstre::mourir() {
}

void Monstre::setCheminSuivi(Chemin* cheminSuivi) {
    this->cheminSuivi = cheminSuivi;
}

Chemin* Monstre::getCheminSuivi() const {
    return cheminSuivi;
}

void Monstre::setVague(Vague* vague) {
    this->vague = vague;
}

Vague* Monstre::getVague() const {
    return vague;
}
