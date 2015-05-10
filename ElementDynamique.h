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
    ElementDynamique();
    
    ElementDynamique(const Point& vitesse, const float& rotation, const float& echelle,
            const Point& position, const float& angle, const float& rayon, bool solide, bool mobile);
    
    //ElementDynamique(Point position, float angle, float rayon, bool solide, bool mobile);

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
