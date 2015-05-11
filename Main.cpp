/* 
 * File:   Main.cpp
 * Author: Nicolas
 *
 * Created on May 5, 2015, 3:21 PM
 */

#include <iostream>
#include <vector>

#include "frame.h"
#include "color.h"
#include "world.h"
#include "control.h"
#include "tools.h"
#include "grid.h"
#include "Point.h"
#include "DetecteurObjetTangible.h"
#include "ObjetTangible.h"

class DetecteurObjetTangible;

using namespace ::mia;

int main(int, char**) {

    mia::World world;
    Frame frame("MoInAg");
    Control control(&frame, &world);

    // World initialization :
    //-----------------------
    world.initialize(Int2(20, 20));

    int nbAgent(10), agent[nbAgent];
    for (int i(0); i < nbAgent; ++i) {
        //ElementDynamique body= ElementDynamique(0.f, 0.f, 0.f,Point( randomFloat()*20.0f, randomFloat()*20.0f ), reduceRadian(randomFloat()*_2PI), 0.2);
        ElementDynamique body = ElementDynamique(Point( randomFloat()*20.0f, randomFloat()*20.0f), 0.f, 0.f, true, true, Point( randomFloat()*20.0f, randomFloat()*20.0f), reduceRadian(randomFloat()*_2PI), 0.2);
        body.setVitesse(Point( cos(body.getAngle()), sin(body.getAngle()) )* 3.f);
        agent[i]= world.createBody(body, 3.0f );
    }

    frame.scale(10.f);
    frame.moveTo(Point(10.0f, 10.0f));

    
    while (!control.end()) {
            
            control.process();
            
            if (!control.pause())
                world.process(1.f / 50.f);

            frame.refresh();
            frame.drawGrid(world);
            frame.drawBodies(world);

            SDL_Delay(50);
    }

    std::cout << "cool !!!" << std::endl;

    return 0;
}

