//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include <SDL_image.h>
#include "SDLGhost.h"
#include "Types.h"

using namespace std;

void SDLGhost::visualize() {
    // Create render position and render
    if(posX>context->getWindowHeigth()){
        posX = -spriteHeigth;
    }
    if(posY>context->getWindowWidth()){
        posY = -spriteWidth;
    }
    if(posX<-spriteHeigth){
        posX = context->getWindowHeigth();
    }
    if(posY<-spriteWidth){
        posY = context->getWindowWidth();
    }
    SDL_Rect position = {posX, posY, spriteHeigth, spriteWidth};
    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), sprites[direction], &position, 0.0, nullptr, SDL_FLIP_NONE);

}

SDLGhost::SDLGhost(int posX, int posY,int speed,SDLContext* context) : Ghost(posX,posY,speed) {
    cout << "Creating SDLGhost" << endl;
    this->context = context;

    //Up Sprite
    sprites[DIR_UP] = new SDL_Rect();
    sprites[DIR_UP]->x = 36;
    sprites[DIR_UP]->y = 226;
    sprites[DIR_UP]->w = 16;
    sprites[DIR_UP]->h = 16;
    //Down Sprite
    sprites[DIR_DOWN] = new SDL_Rect();
    sprites[DIR_DOWN]->x = 20;
    sprites[DIR_DOWN]->y = 242;
    sprites[DIR_DOWN]->w = 16;
    sprites[DIR_DOWN]->h = 16;
    //Left Sprite
    sprites[DIR_LEFT] = new SDL_Rect();
    sprites[DIR_LEFT]->x = 4;
    sprites[DIR_LEFT]->y = 226;
    sprites[DIR_LEFT]->w = 16;
    sprites[DIR_LEFT]->h = 16;
    //Right Sprite
    sprites[DIR_RIGHT] = new SDL_Rect();
    sprites[DIR_RIGHT]->x = 3;
    sprites[DIR_RIGHT]->y = 271;
    sprites[DIR_RIGHT]->w = 16;
    sprites[DIR_RIGHT]->h = 16;

}

