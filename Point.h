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

#ifndef MIA_POINT_H
#define MIA_POINT_H

//#include "int2.h"

#include <iostream>
#include <assert.h>
#include <math.h>

/// 2 dimention floating number.
class Point
{
public :

    // Attributes :
    //-------------
    float x; /// x coordinate.
    float y; /// y coordinate.

    // constructor :
    //--------------
    inline Point():x(0.0f),y(0.0f) {}
    inline Point(const float & f):x(f),y(f) {}
    inline Point(const float &xx, const float &yy):x(xx),y(yy) {}
    inline Point(const Point &v):x(v.x),y(v.y) {}
    inline Point(const Point &v1, const Point &v2):x(v2.x - v1.x),y(v2.y - v1.y) {}
//    inline Point(const Data & d):x(d.value[0]),y(d.value[1]) {}

    // Assignment and cast :
    //---------------------
    inline Point &operator=(const Point &v)
    {
        x= v.x;
        y= v.y;
        return (*this);
    }
    inline Point &operator=(const float &f)
    {
        x= f;
        y= f;
        return *this;
    }

    // Convertion
//    inline operator Int2() {
//        return Int2( (int)x, (int)y );
//    }

    // Equality :
    //-------------
    inline bool operator==(const Point &v) const
    {
        return ( x == v.x && y == v.y );
    }
    inline bool operator!=(const Point &v) const
    {
        return ( x != v.x || y != v.y );
    }

    // Scalar Addition :
    //------------------
    inline Point operator+(const float f)const
    {
        return Point( x+f, y+f );
    }
    inline Point &operator+=(const float f)
    {
        x+= f;
        y+= f;
        return *this;
    }
    inline Point operator-(const float f)const
    {
        return Point( x-f, y-f );
    }

    inline Point &operator-=(const float f) {
        x-= f;
        y-= f;
        return *this;
    }

    // Addition :
    //-----------
    inline Point operator+(const Point &v) const
    {
        return Point( x+v.x, y+v.y );
    }
    inline Point &operator+=(const Point &v)
    {
        x+= v.x;
        y+= v.y;
        return *this;
    }
    inline Point operator-(const Point &v) const
    {
        return Point( x-v.x, y-v.y );
    }
    inline Point &operator-=(const Point &v)
    {
        x-= v.x;
        y-= v.y;
        return *this;
    }
    inline Point operator-()const {
        return Point(-x, -y);
    }

    // Scalar Multiplication :
    //------------------------
    inline Point operator*(const float a) const
    {
        return Point( x*a, y*a );
    }
    inline Point &operator*=(const float a)
    {
        x*= a;
        y*= a;
        return *this;
    }

    // Scalar Division :
    //-------------
    inline Point operator/(const float a)const
    {
        assert(a!=0);
        float ia = 1.0f/a;
        return Point( x*ia, y*ia );
    }
    inline Point &operator/=(const float a)
    {
        assert(a!=0);
        float ia = 1.0f/a;
        x*= ia;
        y*= ia;
        return *this;
    }

    // Colinear vector :
    //------------------
    Point getColinearFromX( float xx )const {
        return Point( xx, y*(xx/x) );
    }
    Point getColinearFromY( float yy )const {
        return Point( x*(yy/y), yy );
    }

    // Dot / cross Product :
    //---------------------------------------
    inline float operator*(const Point &v)const
    {
        return (x*v.x + y*v.y );
    }

    // Cross-Product :
    //----------------
    inline float crossProduct(const Point &w)const
    {
        return (x * w.y - y * w.x);
    }

    // Cross-Product :
    //----------------

    // Normalization :
    //----------------
    inline float normalize()
    {
        float l = length();
        if(l != 0)
        {
            float n = 1.0f/l;
            x*= n;
            y*= n;
        }
        return l;
    }

    inline float normalize( float unit )
    {
        float l = length();
        if(l != 0)
        {
            float n = unit/l;
            x*= n;
            y*= n;
        }
        return l;
    }

    inline Point normalVector( float unit= 1.0f )const
    {
        Point v(0.0f);
        float l= length();
        if(l != 0)
        {
            float n = unit/l;
            v.x= x*n;
            v.y= y*n;
        }
        return v;
    }

    inline float bound(float told)
    {
        float l = length();
        if(l > told)
        {
            float n = told/l;
            x*= n;
            y*= n;
        }
        return l;
    }

    inline float norm2()const {
        return (x*x + y*y);
    }
    inline float length()const {
        return sqrtf( norm2() );
    }

    inline Point orthogonal()const
    {
        return Point(-y, x);
    };
    inline Point orthonormal(float unit= 1.f)const
    {
        Point v= Point(-y, x);
        v.normalize(unit);
        return v;
    }
    inline float orthonormalize()
    {
        float xx= x;
        x= -y;
        y= xx;

        return normalize();
    }
    inline float orthonormalize( float unit )
    {
        float xx= x;
        x= -y;
        y= xx;
        return normalize( unit );
    }

    // Order theory :
    //---------------
    // sur les angles dans le sens trigonométrique

    inline bool operator<(const Point & p) const
    {
        float cp= crossProduct(p);
        if( y < 0.f )
        {
            return ( p.y >= 0.f || cp > 0.f );
        }
        return ( p.y > 0.f && cp > 0.f );
    }

    inline bool operator>(const Point & p) const
    {
        float cp= crossProduct(p);
        if( y <= 0.f )
        {
            return ( p.y < 0.f && cp < 0.f );
        }
        return ( p.y <= 0.f || cp < 0.f );
    }

    // Angle :
    //-------------
    inline float angle()const
    {
        if ( y < 0.0f )
            return ( -acosf( normalVector().x ) );
        return acosf( normalVector().x );
    }

    inline const Point & turn(float delta)
    {
        Point X( cos( delta ), sin( delta ) );
        Point Y( -X.y, X.x );
        (*this)= X * x + Y * y;

        return *this;
    }

    /// return the vector in the direction given by the angle delta.
    static inline Point direction( float delta )
    {
        /// \param delta in radian
        return Point( cos( delta ), sin( delta ) );
    }

    // Basis change :
    //-------------
    inline Point fromBasis( float angle, const Point & refPoint= 0.0f )const
    {
        Point X( cos( angle ), sin( angle ) );
        Point Y( -X.y, X.x );

        return X * x + Y * y + refPoint;
    }

    inline Point inBasis( float angle, const Point & refPoint= 0.0f )const
    {
        Point X( cos( -angle ), sin( -angle ) );
        Point Y( -X.y, X.x );
        return X * (x - refPoint.x) + Y * (y - refPoint.y);
    }

};

// Distance betwen 2 points : :
//-------------
inline float distanceBetween(Point point1, const Point &point2)
{
    point1-= point2;
    return point1.length();
}

inline float distance2Between(Point point1, const Point &point2)
{
    point1-= point2;
    return point1.norm2();
}

// Dot-Product (projection):
//-------------
inline float dotProduct(const Point &v, const Point &w)
{
    return v.x*w.x + v.y*w.y;
}

// Cross product (in Z) :
//-------------
inline float crossProduct(const Point &v,const Point &w)
{
    return (v.x * w.y - v.y * w.x);
}

inline float crossProductNormalized(Point &v, Point &w)
{
    v.normalize();
    w.normalize();
    return (v.x * w.y - v.y * w.x);
}

// Angle :
//-------------
inline Point normalDirection(float theta)
{
    return Point( cos(theta), sin(theta) );
}

inline float angle(const Point & v1, const Point & v2)
{
    return v2.angle() - v1.angle();
}

// Trigo test :
//-------------
inline bool isTrigo(const Point &v1, const Point &v2) {
    return ( crossProduct(v1, v2) > 0.0f );
}
inline bool isnTrigo(const Point &v1, const Point &v2) {
    return ( crossProduct(v1, v2) < 0.0f );
}

inline bool isTrigo(const Point &v1, const Point &v2, const Point &v3)
{
    bool t12(isTrigo(v1, v2) ), t23(isTrigo(v2, v3) ), t13(isTrigo(v1, v3) );
    return (t12 && t23) || (!t13 && ( t12 || t23 ));
}
inline bool isnTrigo(const Point &v1, const Point &v2, const Point &v3)
{
    bool t12(isnTrigo(v1, v2) ), t23(isnTrigo(v2, v3) ), t13(isnTrigo(v1, v3) );
    return (t12 && t23) || (!t13 && ( t12 || t23 ));
}


// tools :
//-------------
inline std::ostream & operator<< ( std::ostream & os, const Point & v )
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

#endif // POINT_H
