#ifndef ElementDynamique_h
#define ElementDynamique_h

#include "ElementVisuel.h"

using namespace std;

class ElementDynamique : public ElementVisuel {
    
protected:
    float vitesse;
    float angle;
    
public:
    virtual void avancerUnPas()  = 0;

    void setAngle(float angle) {
        this->angle = angle;
    }

    float getAngle() const {
        return angle;
    }

    void setVitesse(float vitesse) {
        this->vitesse = vitesse;
    }

    float getVitesse() const {
        return vitesse;
    } 
};

#endif // ElementDynamique_h
