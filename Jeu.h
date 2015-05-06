#ifndef Jeu_h
#define Jeu_h

#include <vector>
#include "Joueur.h"
#include "Vague.h"

using namespace std;

class Jeu {
protected:
    bool etat;
    
public:
    vector<Joueur*> joueurs;
    vector<Vague*> vagues;
    
public:
    virtual void lancer();
    virtual void arreter();
    virtual void terminer();
    void setVagues(vector<Vague*> vagues);
    vector<Vague*> getVagues() const;
    void setJoueurs(vector<Joueur*> joueurs);
    vector<Joueur*> getJoueurs() const;
    void setEtat(bool etat);
    bool isEtat() const;


};

#endif // Jeu_h
