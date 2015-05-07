#ifndef Monstre_h
#define Monstre_h

#include "ElementCombattant.h"
#include "ElementDynamique.h"
#include "Vague.h"
#include "Chemin.h"
#include "Balle.h"

class Monstre : public ElementDynamique, public ElementCombattant {
    
 protected:
    Vague* vague;
    Chemin* cheminSuivi;
    
 public:
    virtual void avancerUnPas();
    virtual void attaquerTour();
    virtual void mourir();
    void setCheminSuivi(Chemin* cheminSuivi);
    Chemin* getCheminSuivi() const;
    void setVague(Vague* vague);
    Vague* getVague() const;

};

#endif // Monstre_h
