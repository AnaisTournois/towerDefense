/*
 * <one line to give the library's name and an idea of what it does.>
 * Copyright (C) 2015  Guillaume L. <guillaume.lozenguez@mines-douai.fr>
 *
 * This program is free software: you can rougeistribute it and/or modify
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


#include "frame.h"

using namespace :: mia;

Frame::Frame(const char * name, int size_x, int size_y ):
    // Window parameters :
    a_halfSsize(size_x/2, size_y/2),
    // 2 Dimention Camera parameters :
    a_position(0., 0.),
    a_scale(1.),
    // SDL Interface :
    a_window(0),
    a_renderer(0),
    a_sdlOk(true),
    // Drawing :
    a_bgCouleur(0x202020FF),
    a_penCouleur(0xA0A0A0FF)
{
    //  Initialize SDL 2 :
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        a_sdlOk= false;
    }

    // Initialize a window :
    a_window = SDL_CreateWindow("Hello World!",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                a_halfSsize.x*2, a_halfSsize.y*2,
                                SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
    if (a_window == 0) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        a_sdlOk= false;
    }

    // Initialize a renderer in the window
    a_renderer = SDL_CreateRenderer(a_window, -1, SDL_RENDERER_ACCELERATED);
    if (a_renderer == 0) {
        SDL_DestroyWindow(a_window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        a_sdlOk= false;
    }

    SDL_SetRenderDrawColor(a_renderer, a_bgCouleur.rouge, a_bgCouleur.vert, a_bgCouleur.bleu, 255);//a_bgCouleur.opacite);
    SDL_RenderClear(a_renderer);
    SDL_RenderPresent(a_renderer);

    SDL_SetRenderDrawColor(a_renderer, a_penCouleur.rouge, a_penCouleur.vert, a_penCouleur.bleu, 255);//a_penCouleur.opacite);
}

Frame::~Frame()
{
    if( a_renderer != 0 )
        SDL_DestroyRenderer(a_renderer);
    if( a_window != 0 )
        SDL_DestroyWindow(a_window);
    SDL_Quit();
}

// Control :

mia::Int2 Frame::windowSize() {
    mia::Int2 size;
    SDL_GetWindowSize( a_window, &(size.x), &(size.y) );
    a_halfSsize= size;
    a_halfSsize/= 2;
    return size;
}

void Frame::refresh() {
    windowSize();

    SDL_RenderPresent(a_renderer);

    SDL_SetRenderDrawColor(a_renderer, a_bgCouleur.rouge, a_bgCouleur.vert, a_bgCouleur.bleu, a_bgCouleur.opacite);
    SDL_RenderClear(a_renderer);
    SDL_SetRenderDrawColor(a_renderer, a_penCouleur.rouge, a_penCouleur.vert, a_penCouleur.bleu, a_penCouleur.opacite);
}

// Getters and Setters :

// 1-Dimention Drawing :
void Frame::drawBasis(float unit) {
    drawLine( mia::Point(-0.1, 0.), mia::Point(unit, 0.));
    drawLine( mia::Point(0.0, 0.), mia::Point(0., unit));
}

// 2-Dimention Drawing :
void Frame::drawCircle(mia::Point center, float radius) {
    int centerX(X(center.x)), centerY(Y(center.y));
    int x(radius* a_scale), y(0), radiusError(1-x);

    while(x >= y) {
        SDL_RenderDrawPoint(a_renderer, x + centerX, y + centerY);
        SDL_RenderDrawPoint(a_renderer, y + centerX, x + centerY);
        SDL_RenderDrawPoint(a_renderer, -x + centerX, y + centerY);
        SDL_RenderDrawPoint(a_renderer, -y + centerX, x + centerY);
        SDL_RenderDrawPoint(a_renderer, -x + centerX, -y + centerY);
        SDL_RenderDrawPoint(a_renderer, -y + centerX, -x + centerY);
        SDL_RenderDrawPoint(a_renderer, x + centerX, -y + centerY);
        SDL_RenderDrawPoint(a_renderer, y + centerX, -x + centerY);
        y++;
        if (radiusError<0)
            radiusError += 2 * y + 1;
        else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}
// Images :
void Frame::printImage(const char * fileName) {
    SDL_Surface *bmp = SDL_LoadBMP( fileName );
    if (bmp == 0)
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;

    SDL_Texture *tex = SDL_CreateTextureFromSurface(a_renderer, bmp);

    if (tex == 0)
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    else
        SDL_RenderCopy(a_renderer, tex, NULL, NULL);
    SDL_FreeSurface(bmp);
    SDL_DestroyTexture(tex);
}


// MoInAg :
void Frame :: drawGrid(const World & w) {
    // Get parametters :
    Int2 worldSize= w.getSize();
    Point corner= toWorld( Int2(0, a_halfSsize.y*2) );
    Point screenSize= Point(a_halfSsize.x*2, a_halfSsize.y*2) / a_scale;

    Int2 first( std::max( (int)(corner.x), 0), std::max( (int)(corner.y), 0) );
    Int2 last( first.x + (int)screenSize.x + 2, first.y + (int)screenSize.y + 2 );
    last= Int2( std::min(last.x, worldSize.x), std::min(last.y, worldSize.y) );

    for(int a= first.x; a <= last.x; a++)
        drawLine( Point(a, first.y), Point(a, last.y) );

    for(int b= first.y; b <= last.y; b++)
        drawLine( Point(first.x, b), Point(last.x, b) );
}

void Frame :: drawBodies(const World & world)
{
    // Data Pointers
    const Patch *patch;
    std::list<int>::const_iterator bodyId;
    Int2 wSize( world.getSize() );
    Point corner= toWorld( Int2(0, a_halfSsize.y*2) );

    // parametters
    Int2 firstPatch, nbPatch( a_halfSsize );

    firstPatch.x= std::max( (int)corner.x, 0 );
    firstPatch.y= std::max( (int)corner.y, 0 );

    nbPatch*= 2/a_scale;
    nbPatch+= 2;
    nbPatch.x= std::min( nbPatch.x, wSize.x - firstPatch.x);
    nbPatch.y= std::min( nbPatch.y, wSize.y - firstPatch.y);

    // Go go go :
    for ( Int2 patchId(0); patchId.x < nbPatch.x; patchId.x++ )
        for ( patchId.y= 0; patchId.y < nbPatch.y; patchId.y++ )
        {
            Int2 op( firstPatch + patchId );
            patch= world.getPatch(op);
            for ( bodyId= patch->a_mobileBody.begin(); bodyId != patch->a_mobileBody.end(); ++bodyId )
            {
                ElementDynamique body( world.getBodyShape( *bodyId ) );
                drawElementDynamique( body );
            }

            for ( bodyId= patch->a_fixedBody.begin(); bodyId != patch->a_fixedBody.end(); bodyId++ )
            {
                ElementDynamique body( world.getBodyShape( *bodyId ) );
                drawElementDynamique( body );
            }
        }
}

void Frame :: drawElementDynamique( const ElementDynamique & bod )
{
    Point orientation( cos(bod.getAngle()), sin(bod.getAngle()) );

    drawCircle( bod.getPosition(), bod.getRayon() );
    drawLine( bod.getPosition(), bod.getPosition() + orientation * bod.getRayon() );
}


