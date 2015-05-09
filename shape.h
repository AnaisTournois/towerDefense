/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2015  Guillaume L. <guillaume.lozenguez@mines-douai.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MIA_SHAPE_H
#define MIA_SHAPE_H

#include "Point.h"


namespace mia
{

class Shape
{
public :

    enum EType
    {
        e_Type_None= 0,
        e_Type_Line,
        e_Type_Circle,
        
        e_NbType
    };

    Point a_position;

private:
    EType a_type;

protected :

    // Contructor / Destructor :
    //--------------------------
    Shape(EType type= e_Type_None):a_type(type) {};
    Shape(EType type, Point position):a_type(type) {
        a_position= position;
    };

    virtual ~Shape() {};

    // Geter / seter :
    //----------------
    virtual int getNbType() {
        return (int)e_NbType;
    }
    virtual EType getType() {
        return a_type;
    }

    // Assignement :
    //--------------
    virtual const Shape &operator=(const Shape &s);

    // Type :
    //-------
    virtual bool is(EType type) {
        return (a_type == type);
    }

    // Size operation :
    //-----------------
    virtual void increaseSize(float) {}

    // Move Operator :
    //----------------
    inline void operator+= ( const Point &v ) {
        a_position+= v;
    }
    inline void operator-= ( const Point &v ) {
        a_position-= v;
    }
};

/// Shape : Line :
///---------------

class Line : public Shape
{
public :
    Point a_vector;

    /// Contructor / Destructor :
    ///--------------------------
    Line():Shape(e_Type_Line) {};
    Line(const Point &A, const Point &B):Shape(e_Type_Line) {
        a_position= A ;
        a_vector= B - A;
    };
    virtual ~Line() {};

    /// Getter && setter :
    ///-------------------
    virtual Point position2()const {
        return (a_position + a_vector);
    }
    virtual float getSlope()const;
    virtual float getYOrigin()const {
        return a_position.y - (getSlope() * a_position.x);
    }

    /// Assignement :
    ///--------------
    virtual const Line & operator=(const Line &s);
};

class Circle : public Shape
{
public :
    float a_radius;

    /// Contructor / Destructor :
    ///--------------------------
    Circle():Shape(e_Type_Circle) {};
    Circle(Point position, float radius):Shape(e_Type_Circle, position) {
        a_radius= radius;
    };
    virtual ~Circle() {};

    /// Assignement :
    ///--------------
    virtual const Circle & operator=(const Circle &c);

    /// Size operator :
    ///----------------
    virtual void increaseSize(float f) {
        a_radius+= f;
    }
};

// Point x Circle :
bool collision(const Point &p1, const Point &p2 );

// Point x Circle :
bool collision(const Point & , const Circle & );

// Point x line :
bool collision(const Point & , const Line & );

// Point x Convex
//      bool collision(const Point & , const Convex & );

// Line x line :
bool collision(Point & , const Line & , const Line &);
bool collision(const Line & , const Line & );

// Circle X Circle
bool collision(Point & between, float & distMin, const Circle & , const Circle & );
bool collision(Point & between, const Circle & , const Circle & );
bool collision(const Circle & c1, const Circle & c2);

// Circle x Line
bool collision(Point & position, const Circle & , const Line &);
//      bool collision(Line &, const Circle & , const Line &, bool verbeux= false );
bool collision(const Circle & , const Line &);


/** Hiding: **/

// Line x line :
bool isHiding(Line &, const Point & origin, const Line & ask, const Line & wall );

};

#endif // MIA_SHAPE_H
