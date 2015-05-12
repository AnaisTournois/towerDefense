#ifndef Vague_h
#define Vague_h

#include <vector>
#include "Monstre.h"

using namespace std;

class Vague {

 public:
    Vague(int niveau);
    ~Vague();
    virtual void lancer();
    void ajouterMonstre(Monstre* monstre);
    void setMonstres(vector<Monstre*> monstres);
    vector<Monstre*> getMonstres() const;
    void setNiveau(int niveau);
    int getNiveau() const;


 protected:
    int niveau;
    vector< Monstre* > monstres;
};

#endif // Vague_h
