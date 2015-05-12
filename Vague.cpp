#include "Vague.h"
//#include <windows.h>
#include <iostream>
#include <unistd.h>
//#include <thread>
//#include <chrono>

Vague::Vague(int niveau) {
    this->niveau = niveau;
}

Vague::~Vague() {
    for (unsigned int i = 0; i < monstres.size(); i++) {
        if (monstres[i] != 0) {
            delete monstres[i];
            monstres[i] = 0;
        }
    }
}

void Vague::lancer() {
    for (unsigned int i = 0; i < monstres.size(); i++) {
        monstres[i]->lancer();
        //Sleep(1000);
    }
}

void Vague::ajouterMonstre(Monstre* monstre) {
    monstres.push_back(monstre);
}

void Vague::setMonstres(vector<Monstre*> monstres) {
    this->monstres = monstres;
}

vector<Monstre*> Vague::getMonstres() const {
    return monstres;
}

void Vague::setNiveau(int niveau) {
    this->niveau = niveau;
}

int Vague::getNiveau() const {
    return niveau;
}
