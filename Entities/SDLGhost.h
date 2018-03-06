//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLGHOST_H
#define GAMETEST_SDLGHOST_H


#include <SDL_render.h>
#include "Ghost.h"
#include "../SDL/SDLContext.h"

class SDLGhost : public Ghost {

public:
    SDLGhost(int posX, int posY, int speed,int color, SDLContext *context);

    void visualize() override;

private:
    //Animation
    int frame = 0;
    static const int ANIMATION_FRAMES = 2;
    static const int ANIMATION_SPEED = 6;

    //Sprite
    static const int spriteWidth = 16;
    static const int spriteHeigth = 16;
    static const int SPRITE_SCALE = 3;
    int COLOR;

    SDL_Rect* sprites[6][ANIMATION_FRAMES];
    SDLContext* context;
};


#endif //GAMETEST_SDLGHOST_H
