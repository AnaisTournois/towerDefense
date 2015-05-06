#ifndef Point_h
#define Point_h

class Point {

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    int getX() {
        return x;
    }
    int setX(int x) {
        this->x = x;
    }
    
    int getY() {
        return y;
    }
    int setY(int y) {
        this->y = y;
    }

 protected:
    int x;
    int y;

};

#endif // Point_h
