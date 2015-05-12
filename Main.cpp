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
#include "Monstre.h"

class DetecteurObjetTangible;

using namespace ::mia;

int main(int, char**) {

    mia::World world;
    Frame frame("MoInAg");
    Control control(&frame, &world);

    // World initialization :
    //-----------------------
    world.initialize(Int2(20, 20));

    int agent[100];
    int nbAgent(1);
    for(int i(0); i < nbAgent; ++i )
    {
        Monstre body= Monstre(0, Point( 1.0f, 10.f ), 0.f, 0.2);
        agent[i]= world.createBody(body, 3.0f );
    }

    frame.scale(20.f);
    frame.moveTo(Point(10.0f, 10.0f));

    vector<ObjetTangible*>* objetsTangibles = new vector<ObjetTangible*>();
    while (!control.end()) {
        int lastSize = objetsTangibles->size();
        
        control.process(objetsTangibles);

        if (lastSize < objetsTangibles->size()) {
            agent[lastSize+nbAgent] = world.createBody((ElementDynamique) objetsTangibles->at(lastSize), 3.f);
        } 
        if (!control.pause())
            world.process(1.f / 50.f);

        frame.refresh();
//        frame.drawGrid(world);
        frame.drawBodies(world);

        SDL_Delay(50);
    }

    std::cout << "cool !!!" << std::endl;

    return 0;
}

