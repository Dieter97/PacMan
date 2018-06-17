//
// Created by dieter on 6/03/18.
//

#include <iostream>
#include "../../include/SDL/SDLPacMan.h"
#include "../../include/Types.h"
using namespace SDL;

/**
 * SDL implementation of the visualisation
 */
void SDLPacMan::visualize() {
    // Create render position and render
    int SDLHeigth = (int)(spriteWidth * context->getSCALE_FACTOR());
    int SDLWidth = (int)(spriteHeigth * context->getSCALE_FACTOR());
    int SDLPosX = (int)std::floor((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR())))+context->getX_offset();
    int SDLPosY = (int) std::floor((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();


    SDL_Rect position = {SDLPosX,SDLPosY,SDLWidth,SDLHeigth};

    SDL_Rect* spriteToLoad;
    switch (this->STATE){
        case DEFAULT:
            spriteToLoad = sprites[DIR_LEFT][1];
            break;
        case DEAD:
            //TODO HANDLE DEAD ANIMATION
            break;
        default:
            spriteToLoad = sprites[this->DIRECTION][frame / ANIMATION_SPEED];
            break;
    }

    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), spriteToLoad, &position, 0.0, nullptr, SDL_FLIP_NONE);
    //Go to next frame
    ++frame;

    //Cycle animation
    if( frame / ANIMATION_SPEED >= ANIMATION_FRAMES )
    {
        frame = 0;
    }
}

/**
 * Creates a SDL pacman and loads the sprites
 * @param posX
 * @param posY
 * @param speed
 * @param context
 */
SDLPacMan::SDLPacMan(float posX, float posY, float speed, SDLContext* context) :
        PacMan(posX, posY, speed) {
    std::cout << "Creating SDLPacMan" << std::endl;
    this->context = context;

    int spriteY = 290;

    for(int i=0; i < 4; i++){
        int spriteX = 65;
        for(int j=0; j < ANIMATION_FRAMES; j++){
            sprites[i][j] = new SDL_Rect();
            sprites[i][j]->x = spriteX;
            sprites[i][j]->y = spriteY;
            sprites[i][j]->w = spriteWidth;
            sprites[i][j]->h = spriteHeigth;
            spriteX += spriteWidth;
        }
        spriteY += spriteHeigth;
    }
}