/* 
 * File:   Cellule.h
 * Author: Nicolas
 *
 * Created on May 5, 2015, 3:24 PM
 */

#ifndef CELLULE_H
#define	CELLULE_H

using namespace std;

class Cellule {
    
public:
    Cellule(int x, int y);
    ~Cellule();
    
    void SetY(int y);
    int GetY() const;
    void SetX(int x);
    int GetX() const;
    
private:
    int x;
    int y;    
};

#endif	/* CELLULE_H */

