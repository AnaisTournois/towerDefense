/* 
 * File:   Cellule.h
 * Author: Nicolas
 *
 * Created on May 5, 2015, 3:24 PM
 */

#ifndef CELLULE_H
#define	CELLULE_H

class Cellule {
    
public:
    Cellule(int x, int y);
    ~Cellule();
    
    int getX();
    int setX(int x);
    
    int getY();
    int setY(int y);
    
private:
    int x;
    int y;
    
};

#endif	/* CELLULE_H */

