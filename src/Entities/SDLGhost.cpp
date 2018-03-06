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
    SDL_Rect position = {posX, posY, spriteHeigth*SPRITE_SCALE, spriteWidth*SPRITE_SCALE};
    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), sprites[direction][frame / ANIMATION_SPEED], &position, 0.0, nullptr, SDL_FLIP_NONE);

    //Go to next frame
    ++frame;

    //Cycle animation
    if( frame / ANIMATION_SPEED >= ANIMATION_FRAMES )
    {
        frame = 0;
    }

}

SDLGhost::SDLGhost(int posX, int posY,int speed,int color,SDLContext* context) : Ghost(posX,posY,speed) {
    cout << "Creating SDLGhost" << endl;
    this->context = context;
    this->COLOR = color;

    int spriteY = 225;

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
}

