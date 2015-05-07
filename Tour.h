#ifndef Tour_h
#define Tour_h

#include <vector>

#include "ElementCombattant.h"
#include "ElementVisuel.h"
#include "Balle.h"
#include "ObjetTangible.h"

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
