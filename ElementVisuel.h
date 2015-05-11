#ifndef ElementVisuel_h
#define ElementVisuel_h

#include "Point.h"

using namespace std;
using namespace mia;


class ElementVisuel {
    
public:
    Point position;
    float angle;
    float rayon;

    bool solide;
    bool mobile;
    
public:
    ElementVisuel();
    
    ElementVisuel(const Point& position = 0.f, const float& angle = 0.f, const float& rayon = 0.f, bool solide = true, bool mobile = true);
    
    void setPosition(Point position) {
        this->position = position;
    }
    Point getPosition() const {
        return position;
    }
    void setAngle(float angle) {
        this->angle = angle;
    }
    float getAngle() const {
        return angle;
    }
    void setRayon(float rayon) {
        this->rayon = rayon;
    }
    float getRayon() const {
        return rayon;
    }
    
    

    void setSolide(bool solide) {
        this->solide = solide;
    }
    bool isSolide() const {
        return solide;
    }
    void setMobile(bool mobile) {
        this->mobile = mobile;
    }
    bool isMobile() const {
        return mobile;
    }

};

#endif // ElementVisuel_h
