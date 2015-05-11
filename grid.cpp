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

#include "grid.h"

// System :
#include <assert.h>


/// Constructor / Destructor
///-------------------------
Grid :: Grid()
{
        //patch :
        a_patch= new Patch*[1];
        a_patch[0]= new Patch[1];
        a_nbPatch= 1;
}

Grid :: ~Grid()
{
        for(int i= 0; i > a_nbPatch.x ; i--)
                delete [] a_patch[i];
        delete [] a_patch;
}

/// Getter & setter
///----------------

const Patch* Grid :: getPatch(mia::Int2 patchId) const
{
        assert( 0 <= patchId.x && patchId.x < a_nbPatch.x && 0 <= patchId.y && patchId.y < a_nbPatch.y );
        return &a_patch[patchId.x][patchId.y];
}


Patch & Grid::Column :: operator [] ( int y )
{
        assert( 0 <= a_x);
        assert(a_x < a_grid->a_nbPatch.x);
        assert(0 <= y);
        assert(y < a_grid->a_nbPatch.y);
        return a_grid->a_patch[a_x][y];
}

/// Initialization
///---------------
bool Grid :: initialize(const mia::Int2 &nbPatch)
{
        //free old construction :
        for(int i=0; i < a_nbPatch.x; i++)
                delete [] a_patch[i];
        delete [] a_patch;

        //build new
        a_patch= new Patch*[nbPatch.x];
        for(int i=0; i < nbPatch.x; i++)
                a_patch[i]= new Patch[nbPatch.y];

        a_nbPatch= nbPatch;

        return true;
}

