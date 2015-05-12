#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementVisuel.h"
#include "ElementCombattant.h"
#include "Joueur.h"
#include "ObjetTangible.h"
#include "Point.h"
#include "world.h"

class Balle;
class Joueur;
//class World;

class Tour : public ElementCombattant, public ObjetTangible {
public:
    
    Tour(vector<Point> points, Point position, float angle, float rayon, bool solide, bool mobile,
         int pointsDeVie, int attaque, int defense, float frequence):
            ObjetTangible(points, position,angle, rayon, solide, mobile), 
            ElementCombattant(pointsDeVie, attaque, defense, frequence) {
    }

    void setProprietaire(Joueur* proprietaire) {
        this->proprietaire = proprietaire;
    }

    Joueur* getProprietaire() const {
        return proprietaire;
    }

    void setPrix(int prix) {
        this->prix = prix;
    }

    int getPrix() const {
        return prix;
    }
    
    virtual void tirerBalle(mia::World* monde){}

protected:
    int prix;
    Joueur* proprietaire;
};

#endif // Tour_h
