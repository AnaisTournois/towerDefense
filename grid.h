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

#ifndef MIA_GRID_H
#define MIA_GRID_H

// System :
#include <list>

// SiPlEn :
#include "int2.h"

struct Patch
{
        std::list<int> a_mobileBody;
        std::list<int> a_fixedBody;
};

class Grid
{
        friend class Column;

public:
        class Column
        {
        protected :
                Grid * a_grid;
                int a_x;

        public :
                // Constructor destructor
                Column( Grid * g, int l= 0):a_grid(g),a_x(l){}
                virtual ~Column(){}

                Patch & operator [] ( int y );
        };

protected :
        //patch :
        mia::Int2 a_nbPatch;
        Patch **a_patch;

public :
// Constructor / Destructor
//-------------------------
        Grid();
        ~Grid();

// Initialization
//---------------
        bool initialize(const mia::Int2 &nbPatch);

// Getter / Setter :
//------------------
        mia::Int2 getSize() const { return a_nbPatch; }
        const Patch* getPatch( mia::Int2 patchId ) const;
        inline Grid::Column operator [] ( int x ){ Column c(this, x); return c; }
};

#endif // MIA_GRID_H
