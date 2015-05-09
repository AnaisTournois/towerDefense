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

#include "shape.h"


using namespace mia;

const Shape & Shape :: operator=(const Shape &s)
{
    a_type= s.a_type;
    a_position= s.a_position;

    return *this;
}

/********************************************************/
/**                   Line :                           **/
/********************************************************/

float Line :: getSlope()const
{
    if( a_vector.x != 0.0f )
        return (a_vector.y / a_vector.x);
    return 0.0f;
}

const Line & Line :: operator=(const Line &s)
{
    Shape::operator=(s);
    a_vector= s.a_vector;

    return *this;
}


const Circle & Circle :: operator=(const Circle &s)
{
    Shape::operator=(s);
    a_radius= s.a_radius;

    return *this;
}


float scale= 0.001f;

bool mia :: collision(const Point &p1, const Point &p2 )
{
    return collision( p1, Circle(p2, scale) );
}

//Point x Circle :
//----------------

bool mia :: collision(const Point &p, const Circle &c)
{
    Point between= c.a_position - p;
    float distMin= c.a_radius;

    return ( between.norm2() < (distMin * distMin) );
}


// Point x line :
//---------------

bool mia :: collision(const Point &v, const Line &l)
{
    Line l1( v, l.a_position );
    Line l2( v, l.a_position + l.a_vector );

    return ( l1.a_vector.length() + l2.a_vector.length() ) < l.a_vector.length() + (2.0f * scale);
}


// Line x line :
//--------------

bool mia :: collision(Point& collide, const Line &l1, const Line &l2)
{
    //TODO : A reprendre :
    float a1= l1.getSlope();
    float a2= l2.getSlope();
    float b1= l1.a_position.y - a1 * l1.a_position.x;
    float b2= l2.a_position.y - a2 * l2.a_position.x;

    if( a1 == a2 )
    {
        return false;
    }

    collide.x= (b2 - b1) / (a1 - a2);
    collide.y= a1 * collide.x + b1;

    if( (unsigned int)b2 < (unsigned int)b1 )
    {
        collide.y= a2 * collide.x + b2;
    }

    Point vect1( l1.a_position, collide );
    Point vect2( l2.a_position, collide );

    return (vect1.x * l1.a_vector.x) >= 0.0f
           && (vect1.y * l1.a_vector.y) >= 0.0f
           && vect1.norm2() <= l1.a_vector.norm2()
           && (vect2.x * l2.a_vector.x) >= 0.0f
           && (vect2.y * l2.a_vector.y) >= 0.0f
           && vect2.norm2() <= l2.a_vector.norm2();
}

bool mia :: collision(const Line& l1, const Line& l2)
{
    Point collide;
    return collision(collide, l1, l2);
}


// Circle x Circle :
//------------------

bool mia :: collision(Point & between, const Circle & c1, const Circle & c2 )
{
    between= c2.a_position - c1.a_position;
    float distMin= c1.a_radius + c2.a_radius;

    return ( between.norm2() < (distMin*distMin) );
}

bool mia :: collision(const Circle &c1, const Circle &c2)
{
    Point between= c2.a_position - c1.a_position;
    float distMin= c1.a_radius + c2.a_radius;

    return ( between.norm2() < (distMin*distMin) );
}

bool mia :: collision(Point &between, float &distMin, const Circle &c1, const Circle &c2)
{
    between= c2.a_position - c1.a_position;
    distMin= c1.a_radius + c2.a_radius;

    return ( between.norm2() < (distMin*distMin) );
}

// Circle x Line
bool mia :: collision(Point& position, const Circle &c, const Line &l)
{
    Line diametre;

    diametre.a_vector.x = l.a_vector.y;
    diametre.a_vector.y = -l.a_vector.x;
    diametre.a_vector.normalize();
    diametre.a_vector*= c.a_radius;

    diametre.a_position= c.a_position - diametre.a_vector;
    diametre.a_vector*= 2.0f;

    if ( collision( position, l, diametre ) )
    {
        return true;
    }

    position= l.a_position + l.a_vector;

    if( mia :: collision( position, c ) )
    {
        Point v1( c.a_position, position );
        Point v2( c.a_position, l.a_position );

        if( v2.norm2() < v1.norm2() )
            position= l.a_position;

        return true;
    }

    position= l.a_position;
    if( collision( position, c ) )
    {
        return true;
    }

    return false;
}


bool mia :: collision(const Circle &c, const Line &l)
{
    Point f(0.f);
    return collision( f, c, l);
}


// Line x line :
bool mia :: isHiding(Line & askMin, const Point & origin, const Line & ask, const Line & wall)
{
    Point colidePos;
    Line test1= Line( origin, ask.a_position );
    Line test2= Line( origin, ask.a_position + ask.a_vector );
    bool colide= mia::collision( colidePos, ask, wall );
    bool mask1= mia::collision( test1, wall );
    bool mask2= mia::collision( test2, wall );
    float distMax= std::max( test1.a_vector.length(), test2.a_vector.length() ) * 2.0f;
    askMin= ask;

    if( mask1 && mask2 )
        return true;

    if ( mask1 )
    {
        Point pos;
        Point extrem= wall.a_position;
        Line vue( origin, extrem );
        vue.a_vector.normalize( distMax );
        bool cool= mia::collision( pos, ask, vue );

        if( !cool || ( colide && mia::collision(pos, colidePos) ) )
        {
            extrem+= wall.a_vector;
            vue= Line( origin, extrem );
            vue.a_vector.normalize( distMax );
            cool= mia::collision( pos, ask, vue );
        }

        vue= Line( origin, extrem );
        Line vue2( origin, pos );

        if( cool && vue2.a_vector.norm2() > vue.a_vector.norm2() )
        {
            askMin= Line( pos, ask.a_position + ask.a_vector );
        }
        else if( colide )
        {
            //cout << "ide";
            askMin= Line( colidePos, ask.a_position + ask.a_vector );
        }
    }

    else if ( mask2 )
    {
        Point pos;
        Point extrem= wall.a_position;
        Line vue( origin, extrem );
        vue.a_vector.normalize( distMax );
        bool cool= mia::collision( pos, ask, vue );

        if( !cool || ( colide && mia::collision(pos, colidePos) ) )
        {
            extrem+= wall.a_vector;
            vue= Line( origin, extrem );
            vue.a_vector.normalize( distMax );
            cool= mia::collision( pos, ask, vue );
        }

        vue= Line( origin, extrem );
        Line vue2( origin, pos );

        if( cool && vue2.a_vector.norm2() > vue.a_vector.norm2() )
        {
            askMin= Line( pos, ask.a_position );
        }
        else if( colide )
        {
            //cout << "ide";
            askMin= Line( colidePos, ask.a_position );
        }
    }

    return askMin.a_vector.norm2() < (scale * scale);
}
