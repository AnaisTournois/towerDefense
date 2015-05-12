#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementVisuel.h"
#include "ElementCombattant.h"
#include "Joueur.h"
#include "ObjetTangible.h"
#include "Point.h"

class Balle;
class Joueur;


class Tour : public ElementVisuel, public ElementCombattant, public ObjetTangible {
public:
    
    Tour(Point position, float angle, float rayon, bool solide, bool mobile,
         int pointsDeVie, int attaque, int defense, float frequence):
            ElementVisuel(position,angle, rayon, solide, mobile), 
            ElementCombattant(pointsDeVie, attaque, defense, frequence) {
    }

    virtual Balle* tirerBalle() = 0;

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

protected:
    int prix;
    Joueur* proprietaire;
};

#endif // Tour_h
