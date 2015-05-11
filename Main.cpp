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

#include <iostream>
#include "frame.h"

#include "world.h"
#include "control.h"
#include "tools.h"

using namespace :: mia;

int main(int, char**) {

    World world;
    Frame frame("MoInAg");
    Control control(&frame, &world);

    // World initialization :
    //-----------------------
    world.initialize( Int2(20, 20) );

    int nbAgent(120), agent[nbAgent];
    for(int i(0); i < nbAgent; ++i )
    {
        ElementDynamique body= ElementDynamique( Point( randomFloat()*20.0f, randomFloat()*20.0f ), reduceRadian(randomFloat()*_2PI), 0.2);
        body.setVitesse(Point( cos(body.getAngle()), sin(body.getAngle()) )* 3.f);
        agent[i]= world.createBody(body, 3.0f );
    }
    
    frame.scale( 10.f );
    frame.moveTo( Point(10.0f, 10.0f) );

    // Loops Process :
    //----------------
    while( !control.end() )
    {
        control.process();

        if( !control.pause() )
            world.process(1.f/500.f);
        
//        frame.drawGrid( &world, white );
        frame.refresh();
//        frame.drawGrid( world );
        frame.drawBodies( world );
      
        SDL_Delay(50);
    }

    std::cout << "cool !!!" <<  std::endl;

    return 0;
}
