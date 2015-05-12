#include "Jeu.h"

Jeu::Jeu(int nombreJoueurs) {
    for (int i = 0; i < nombreJoueurs; i++) {
        joueurs.push_back(new Joueur(i));
    }
    int nombreDeVagues = 1;
    for (int i = 0; i < nombreDeVagues; i++) {
        vagues.push_back(new Vague(i));
        int nombreDeMonstres = i;
        for (int j = 0; j < nombreDeMonstres; j++) {
            vagues[i]->ajouterMonstre(new Monstre(0));
        }
    }
}

Jeu::~Jeu() {
    for (int i = 0; i < joueurs.size(); i++) {
        delete joueurs[i];
        joueurs[i] = 0;
    }
    for (int i = 0; i < vagues.size(); i++) {
        delete vagues[i];
        vagues[i] = 0;
    }
}

void Jeu::lancer() {
}

void Jeu::arreter() {
}

void Jeu::terminer() {
}

void Jeu::setVagues(vector<Vague*> vagues) {
    this->vagues = vagues;
}

vector<Vague*> Jeu::getVagues() const {
    return vagues;
}

void Jeu::setJoueurs(vector<Joueur*> joueurs) {
    this->joueurs = joueurs;
}

vector<Joueur*> Jeu::getJoueurs() const {
    return joueurs;
}

void Jeu::setEtat(bool etat) {
    this->etat = etat;
}

bool Jeu::getEtat() const {
    return etat;
}
