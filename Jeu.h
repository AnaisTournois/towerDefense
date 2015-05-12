#ifndef Jeu_h
#define Jeu_h

#include <vector>
#include "Joueur.h"
#include "Vague.h"
#include "ObjetTangible.h"

using namespace std;

class Jeu {
protected:
    bool etat;

public:
    vector<Joueur*> joueurs;
    vector<Vague*> vagues;

public:
    Jeu(int nombreJoueurs);
    ~Jeu();
    virtual void lancer();
    virtual void arreter();
    virtual void terminer();
    void setVagues(vector<Vague*> vagues);
    vector<Vague*> getVagues() const;
    void setJoueurs(vector<Joueur*> joueurs);
    vector<Joueur*> getJoueurs() const;
    void setEtat(bool etat);
    bool getEtat() const;
    ObjetTangible* detecterObjetTangible();


};

#endif // Jeu_h
