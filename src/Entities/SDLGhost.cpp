//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include <SDL_image.h>
#include "../../include/SDLGhost.h"
#include "../../include/Types.h"

using namespace std;

void SDLGhost::visualize() {
    // Create render position and render
    int SDLPosX = (int)floorf((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR())))+context->getX_offset();
    int SDLPosY = (int) floorf((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();;
    int SDLHeigth = (int)(spriteWidth * context->getSCALE_FACTOR());
    int SDLWidth = (int)(spriteHeigth * context->getSCALE_FACTOR());

    SDL_Rect position = {SDLPosX,SDLPosY,SDLWidth,SDLHeigth};

    SDL_Rect* spriteToLoad;
    switch (this->STATE){
        case FLEE:
            spriteToLoad = sprites[FLEE][frame / ANIMATION_SPEED];
            break;
        case DEAD:
            spriteToLoad = dead_sprite[DIRECTION];
            break;
        default:
            spriteToLoad = sprites[this->DIRECTION][frame / ANIMATION_SPEED];
            break;
    }

    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), spriteToLoad, &position, 0.0, nullptr, SDL_FLIP_NONE);

    //Go to next frame
    ++frame;

    //Cycle animation
    if( frame / ANIMATION_SPEED >= ANIMATION_FRAMES ) {
        frame = 0;
    }

}

SDLGhost::SDLGhost(float posX, float posY,float speed,int color,SDLContext* context) :
        Ghost(posX,posY,speed) {
    cout << "Creating SDLGhost" << endl;
    this->context = context;
    this->COLOR = color;

    int spriteY = 225;

    //Load alive sprite based on color
    for(int i=0;i<4;i++){
        int spriteX = 5+((COLOR)*2*spriteWidth);
        for(int j=0;j<ANIMATION_FRAMES;j++){
            sprites[i][j] = new SDL_Rect();
            sprites[i][j]->x = spriteX;
            sprites[i][j]->y = spriteY;
            sprites[i][j]->w = spriteWidth;
            sprites[i][j]->h = spriteHeigth;
            spriteX += spriteWidth;
        }
        spriteY += spriteHeigth;
    }

    //Load flee sprites
    spriteY = 226;
    for(int i=4;i<6;i++){
        int spriteX = 126;
        for(int j=0;j<2;j++){
            sprites[i][j] = new SDL_Rect();
            sprites[i][j]->x = spriteX;
            sprites[i][j]->y = spriteY;
            sprites[i][j]->w = spriteWidth;
            sprites[i][j]->h = spriteHeigth;
            spriteX += spriteWidth;
        }
        spriteY += spriteHeigth;
    }

    //Load dead sprites
    spriteY = 256;
    int k = 0;
    for(int i=0;i<2;i++){
        int spriteX = 126;
        for(int j=0;j<2;j++){
            dead_sprite[k] = new SDL_Rect();
            dead_sprite[k]->x = spriteX;
            dead_sprite[k]->y = spriteY;
            dead_sprite[k]->w = spriteWidth;
            dead_sprite[k]->h = spriteHeigth;
            spriteX += spriteWidth;
            k++;
        }
        spriteY += spriteHeigth;
    }
}