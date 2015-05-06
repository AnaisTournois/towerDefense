#ifndef ElementVisuel_h
#define ElementVisuel_h

#include "Point.h"

using namespace std;

class ElementVisuel {
protected:
    float rayon;
    Point* position;
    
public:
    void SetPosition(Point* position) {
    this->position = position;
    }

    Point* GetPosition() const {
        return position;
    }

    void SetRayon(float rayon) {
        this->rayon = rayon;
    }

    float GetRayon() const {
        return rayon;
    }
};

#endif // ElementVisuel_h
