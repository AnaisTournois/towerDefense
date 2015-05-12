#ifndef Monstre_h
#define Monstre_h

#include "ElementDynamique.h"
#include "ElementCombattant.h"
#include "Chemin.h"
#include "Tour.h"

class Monstre : public mia::ElementDynamique, public ElementCombattant {
protected:
    Chemin* cheminSuivi;

public:
    Monstre(Chemin* cheminSuivi, const Point& position = Point(1.f, 10.f), const float& angle = 0.f, const float& rayon = 0.2f,
            bool solide = true, bool mobile = true,
            const Point& vitesse = Point(5.f, 0.f), const float& rotation = 0.f, const float& echelle = 0.f,
            const int pointsDeVie = 10, const int attaque = 1, const int defense = 0, const float frequence = 1.0f);
    void lancer();
    virtual void avancerUnPas();
    virtual void attaquerTour(Tour* tour);
    virtual void mourir();
    Chemin* getCheminSuivi() const;

};

#endif // Monstre_h
