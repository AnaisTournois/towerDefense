#ifndef ElementVisuel_h
#define ElementVisuel_h

#include "Point.h"

using namespace std;

class Point;

class ElementVisuel {
    
protected:
    Point position;
    float angle;
    float rayon;

    bool solide;
    bool mobile;
    
public:
    ElementVisuel(const Point& position, const float& angle, const float& rayon, bool solide, bool mobile);
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
