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

#include "world.h"

// System :
#include <iostream>
#include <fstream>


//SiPlEn :
#include "shape.h"
#include "Point.h"
#include "tools.h"
// Namespace :
using namespace std;
using namespace mia;

// Constructor Destructor :
//-------------------------
World :: World()
{
}

World :: ~World()
{
}

// Agent methode :
//----------------
bool World :: initialize( mia::Int2 size, bool close)
{
    a_grid.initialize(size);

    if( close )
    {
        Point C( (float)size.x - 0.01f, (float)size.y - 0.01f );
        Point A(0.01f), B(A.x, C.y), D(C.x, A.y);

        createWall( A, B);
        createWall( B, C);
        createWall( C, D);
        createWall( D, A);
    }

    return true;
}

bool World :: initialize( const char * file, bool close)
{
    fstream filestr( file, fstream::in | fstream::out );
    assert( filestr.is_open() );

    Int2 size;
    int nbObstacles;

    filestr >> size.x >> size.y >> nbObstacles;
    initialize(size, close);

    for(int iObs=0; iObs < nbObstacles; ++iObs)
    {
        int nbPoint;
        Point last;
        filestr >> nbPoint >> last.x >> last.y;
        for(int iP=1; iP < nbPoint; ++iP)
        {
            Point point;
            filestr >> point.x >> point.y;
            createWall(last, point);
            last= point;
        }
    }

    filestr.close();
    return true;
}

void World :: process(float dTime)
{
    list<int> bodyIdList;
    list<int>::iterator it1, it2;
    Int2 worldSize( a_grid.getSize() );

    // process world phisical Laws :
    Point between;
    float distMin;

    for ( int x= 0; x < worldSize.x; ++x )
        for ( int y= 0; y < worldSize.y; ++y )// TODO : maintain a list of interesting cells.
            bodyIdList.merge( a_grid[x][y].a_mobileBody );

    for ( it1= bodyIdList.begin(); it1 != bodyIdList.end(); ++it1 )
    {
        Body * bod= &a_body[ *it1 ];

        // move the shape :
        Point move= bod->shape.getVitesse() * dTime;
        bod->shape.getPosition()+= bod->shape.getVitesse() * dTime;

        //turn :
        float angle= bod->shape.getRotation() * dTime;
        bod->shape.setAngle(bod->shape.getAngle() + angle);
        bod->shape.setAngle(reduceRadian( bod->shape.getAngle() ));

        // Non onolomic :
        Point ortho(0.0f, 1.0f);
        ortho.turn( bod->shape.getAngle() );
        float power= ortho * bod->shape.getVitesse();

        // aderance : TODO : faire sa plus propre
        bod->shape.getVitesse()-= ortho * power * dTime * 2.0f;
    }

    int rand= randomInt();

    while ( !bodyIdList.empty() )
    {
        // Collision
        int iBody= bodyIdList.front();
        bodyIdList.pop_front();
        // TODO : compute the collision average velocity in case of multi-colisions
        // TODO : compute rotation impact

        Int2 pathId( a_body[iBody].shape.getPosition() );
        Int2 first, last;
        first.x= max(0, pathId.x-1);
        first.y= max(0, pathId.y-1);
        last.x= min(worldSize.x, pathId.x+2);
        last.y= min(worldSize.y, pathId.y+2);

        for (int x= first.x; x < last.x; x++)
            for (int y= first.y; y < last.y; y++)
            {
                // Collision with mobile Body...
                for ( it2= a_grid[x][y].a_mobileBody.begin(); it2 != a_grid[x][y].a_mobileBody.end(); ++it2 )
                        if ( mia::collision( between, distMin, bodyShape( iBody ), bodyShape( *it2 ) ) )
                {
                        distMin+= 0.001;
                        float dist= distMin - between.normalize();

                        // Collision power = projection of 2 speed on between :
                        float power= (between * a_body[iBody].shape.getVitesse()) + (between * -a_body[*it2].shape.getVitesse());
                        power= max( power, -power);

                        // Position :
                        a_body[iBody].shape.getPosition()-= between * dist * 0.5f;
                        a_body[*it2].shape.getPosition()+= between * dist * -0.5f;

                        // speed
                        a_body[iBody].shape.getVitesse()-= between * power * 0.75f; // * (0.5f + rapport d'innerti); ou :
                        a_body[*it2].shape.getVitesse()+= between * power * 0.75f; // * (0.5f + a_body[iBody].shape.a_inerti * 0.5);
                }


                // Collision with fixed Body...
                for ( it2= a_grid[x][y].a_fixedBody.begin(); it2 != a_grid[x][y].a_fixedBody.end(); ++it2 )
                    if ( mia::collision( between, distMin, bodyShape( iBody ), bodyShape( *it2 ) ) )
                {
                    float dist= distMin - between.normalize() + 0.01f;

                    // Collision power = projection of the mobile agent speed on between :
                    float power= between * a_body[iBody].shape.getVitesse();
                    power= max( power, 0.f);

                    // Position :
                    a_body[iBody].shape.getPosition()-= between * dist;

                    // Speed :
                    a_body[iBody].shape.getVitesse()-= between * power * 1.5; //(1.f + a_body[iBody].shape.a_inerti);
                }
            }

        // World limits :
        if ( a_body[iBody].shape.getPosition().x < a_body[iBody].shape.getAngle() )
        {
            a_body[iBody].shape.getPosition().x= a_body[iBody].shape.getAngle();
            a_body[iBody].shape.getVitesse().x= 0.f; //*= -0.5; //a_body[iBody].shape.a_inerti - 1;
        }
        else if ( a_body[iBody].shape.getPosition().x > ( (float)worldSize.x - a_body[iBody].shape.getAngle() ) )
        {
            a_body[iBody].shape.getPosition().x= (float)worldSize.x - a_body[iBody].shape.getAngle();
            a_body[iBody].shape.getVitesse().x= 0.f; //*= -0.5; //a_body[iBody].shape.a_inerti - 1;
        }

        if ( a_body[iBody].shape.getPosition().y < a_body[iBody].shape.getAngle() )
        {
            a_body[iBody].shape.getPosition().y= a_body[iBody].shape.getAngle();
            a_body[iBody].shape.getVitesse().y= 0.f; //*= -0.5; //a_body[iBody].shape.a_inerti - 1;
        }
        else if ( a_body[iBody].shape.getPosition().y > ( (float)worldSize.y - a_body[iBody].shape.getAngle() ) )
        {
            a_body[iBody].shape.getPosition().y= (float)worldSize.y - a_body[iBody].shape.getAngle();
            a_body[iBody].shape.getVitesse().y= 0.f; //*= -0.5; //a_body[iBody].shape.a_inerti - 1;
        }

        // reset in grid :
        pathId= a_body[iBody].shape.getPosition();
        a_grid[pathId.x][pathId.y].a_mobileBody.push_back( iBody );
    }
}

int World :: createBody( const ElementDynamique & shape, float pr)
{
    int idBody= a_body.push( Body(shape, pr) );

    if( shape.isMobile() )
        a_grid[(int)(shape.getPosition().x)][(int)(shape.getPosition().y)].a_mobileBody.push_back( idBody );
    else
        a_grid[(int)(shape.getPosition().x)][(int)(shape.getPosition().y)].a_fixedBody.push_back( idBody );

    return idBody;
}

int World :: createWall(const Point p1, const Point p2, float radius, float ratio)
{
    Point step(p1, p2);
    float dist= step.normalize();
    int nbBody= (int)( dist / (radius*ratio) );
    step*= dist / (float)nbBody;
    ElementDynamique shape(0.f, 0.f, 0.f,p1 + step*0.5f, step.angle(), radius, true, false);
    //ElementDynamique shape(p1 + step*0.5f, step.angle(), radius, true, false);

    for(int i= 0; i < nbBody; ++i)
    {
        createBody(shape);
        shape.getPosition()+= step;
    }

    return nbBody;
}
