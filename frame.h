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

#ifndef FRAME_H
#define FRAME_H

#include "int2.h"
#include "Point.h"
#include "Couleur.h"
#include "world.h"

#include <iostream>
#include <stdlib.h>

#include <SDL2/SDL.h>
class Couleur;
class World;


namespace mia{
    
class Frame
{
protected:
    // Window parameters :
    Int2 a_halfSsize;

    // 2 Dimention Camera parameters :
    Point a_position;
    float a_scale;

    // SDL Interface :
    SDL_Window * a_window;
    SDL_Renderer * a_renderer;
    bool a_sdlOk;

    // Drawing :
    Couleur a_bgCouleur, a_penCouleur;

    // InnerTools :
    inline int X(float x)const {
        return (int)((x-a_position.x)*a_scale) + a_halfSsize.x;
    }

    inline int Y(float y)const {
        return -(int)((y-a_position.y)*a_scale) + a_halfSsize.y;
    }

public:
    // Constructor, Destructor :
    Frame(const char * name, int size_x =640, int size_y =480 );
    ~Frame();

    // Control :
    void scaleIn(){ a_scale*= 1.2f; }
    void scaleOut(){ a_scale*= 0.8f; }
    void moveTo(const Point & p){ a_position= p; }
    void movePixel(const Int2 & pix){ a_position+= Point(pix.x/a_scale, -pix.y/a_scale); }

    // Windows :
    mia::Int2 windowSize();
    void refresh();

    // Getters and Setters :
    inline Couleur penCouleur()const { return a_penCouleur; };
    inline void penCouleur(Couleur newCouleur ) { a_penCouleur= newCouleur; };
    inline float scale()const { return a_scale; };
    inline void scale(float newScale) { a_scale= newScale; };

    inline Int2 toPixel( const Point & point )const { return Int2( X(point.x), Y(point.y) ); }
    inline Point toWorld( const Int2 & pixel )const { return Point( (pixel.x-a_halfSsize.x)/a_scale + a_position.x, -(pixel.y-a_halfSsize.y)/a_scale + a_position.y); }

    // 1-Dimention Drawing :
    inline void drawPoint( Point p ) { SDL_RenderDrawPoint(a_renderer, X(p.x), Y(p.y) ); }
    inline void drawLine( Point p1, Point p2 ) { SDL_RenderDrawLine(a_renderer, X(p1.x), Y(p1.y), X(p2.x), Y(p2.y) ); }

    // 2-Dimention Drawing :
    void drawCircle(Point center, float radius);

    // Images :
    void printImage(const char * fileName);
    
    // References :
    void drawBasis(float unit= 1.);
    
    //MoInAg :
    void drawGrid(const World& w);
    void drawBodies(const World& w);

    void drawElementDynamique( const ElementDynamique & bod );
};

};
#endif // FRAME_H
