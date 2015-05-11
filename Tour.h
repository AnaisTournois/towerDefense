#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementCombattant.h"
#include "ElementVisuel.h"
#include "Joueur.h"
#include "ObjetTangible.h"

class Balle;
class Joueur;


class Tour : public ElementCombattant, public ObjetTangible {
public:

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
