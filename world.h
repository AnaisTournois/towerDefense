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

#ifndef MIA_WORLD_H
#define MIA_WORLD_H

#include "collection.h"
#include "ElementDynamique.h"
#include "shape.h"
#include "grid.h"

namespace mia{

struct Body
{
        mia::ElementDynamique shape;

        Body():shape(){}
        Body(const mia::ElementDynamique & s, float pr= 1.f):shape(s){}
        Body(int o, const mia::ElementDynamique & s, float pr= 1.f):shape(s){}

        const Body & operator=(const Body & b){
                shape= b.shape;
                return *this;
        };
};

class World
{
public :

        enum EPerception
        {
                perception_communication= 0,
                perception_position,
                perception_movement,
                perception_wall,
                perception_mobile,
                perception_control,

                perception_number
        };

        enum EAction
        {
                action_communication= 0,
                action_move,

                action_number
        };

protected :
        // World Element :
        mia::collection<Body> a_body;

        // Grid :
        //-------
        Grid a_grid;

public :
        // Constructor Destructor :
        //-------------------------
        World();
        virtual ~World();


        virtual bool initialize( mia::Int2 size, bool close= true);
        virtual bool initialize( const char * file, bool close= true);
        virtual void process(float dTime);

        // factory function :
        //-------------------
        static World * factory(int= 0){ return new World(); }
        virtual int createBody(const mia::ElementDynamique & body, float pr= 0.1f);
        virtual int createWall(const mia::Point p1, const mia::Point p2, float radius= 0.06f, float ratio= 1.90f);

        // Getter / Setter :
        //------------------
        virtual mia::Int2 getSize() const { return a_grid.getSize(); };
        virtual const Patch* getPatch( mia::Int2 patchId) const { return a_grid.getPatch( patchId ); };
         inline virtual mia::Circle bodyShape(int id)const
         {
                 return mia::Circle( a_body(id).shape.getPosition(), a_body(id).shape.getRayon() );
         }

        // Body Managment :
        //-----------------
        virtual mia::ElementDynamique getBodyShape( int id ) const { return a_body(id).shape; }

};

};
#endif // MIA_WORLD_H
