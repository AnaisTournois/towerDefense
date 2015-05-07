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
    
private:
    int x;
    int y; 
    
public:
    Cellule(int x, int y);
    
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
   
};

#endif	/* CELLULE_H */

