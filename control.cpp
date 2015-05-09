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

#include "control.h"

using namespace :: mia;

Control::Control( Frame * frame, World * target ):
    a_frame(frame),
    a_target(target),
    a_end(false),
    a_pause(false),
    a_mouseControl(false)
{

}


//Process function :
void Control::process()
{
    SDL_Event event;
    Couleur white( 255, 255, 255 );

    Int2 mouseMove(0, 0);
    while( SDL_PollEvent( &event ) ) {
        a_end= a_end || event.type == SDL_QUIT;
        
        if ( event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_PAUSE) )
            a_pause= !a_pause;

        a_mouseControl= a_mouseControl || ( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT );
        a_mouseControl= a_mouseControl && !(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT);

        if( event.type == SDL_MOUSEWHEEL ) {
            if( event.wheel.y < 0 )
                a_frame->scaleOut();
            else a_frame->scaleIn();
        }
        else if( event.type == SDL_MOUSEMOTION ) {
            mouseMove.x+= event.motion.xrel;
            mouseMove.y+= event.motion.yrel;
        }
    }

    if( a_mouseControl && mouseMove != Int2(0, 0) ) {
        mouseMove*= -1;
        a_frame->movePixel( mouseMove );
    }

}

