#ifndef ElementDynamique_h
#define ElementDynamique_h

#include "ElementVisuel.h"

using namespace std;
using namespace mia;
namespace mia {

class ElementDynamique : public ElementVisuel {
    
protected:

    Point vitesse;
    float rotation;
    float echelle;

public:
    /// Contructor / Destructor :
    ///--------------------------
    ElementDynamique(const Point& position = 0.f, const float& angle = 0.f, const float& rayon = 0.f, bool solide = true, bool mobile = true,
                     const Point& vitesse = 0.f, const float& rotation = 0.f, const float& echelle = 0.f);

    // Assignation :
    //--------------
//    virtual const ElementDynamique &operator=( const ElementDynamique& elementDynamique );

    // Comparaison      :
    //------------------
    virtual bool operator==( const ElementDynamique& elementDynamique );

    /// Process Dynamiq :
    ///------------------
    virtual void avancerUnPas(float temps);

    /// Getter / Setter :
    ///------------------
    void setVitesse(Point vitesse) {
        this->vitesse = vitesse;
    }
    Point getVitesse() const {
        return vitesse;
    }
    void setRotation(float rotation) {
        this->rotation = rotation;
    }
    float getRotation() const {
        return rotation;
    }
    void setEchelle(float echelle) {
        this->echelle = echelle;
    }
    float getEchelle() const {
        return echelle;
    }

};
};

#endif // ElementDynamique_h
