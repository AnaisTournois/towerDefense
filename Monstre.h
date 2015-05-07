#ifndef Monstre_h
#define Monstre_h

#include "ElementCombattant.h"
#include "ElementDynamique.h"
#include "Chemin.h"

class Monstre : public ElementDynamique, public ElementCombattant {
    
 protected:
    Chemin* cheminSuivi;
    
 public:
    virtual void avancerUnPas();
    virtual void attaquerTour();
    virtual void mourir();
    Chemin* getCheminSuivi() const;

};

#endif // Monstre_h
