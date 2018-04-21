//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLGHOST_H
#define GAMETEST_SDLGHOST_H


#include <SDL_render.h>
#include "Ghost.h"
#include "SDLContext.h"

class SDLGhost : public Ghost {

public:
    SDLGhost(float posX, float posY, float speed, int color, SDLContext *context);

    void visualize() override;

private:
    //Animation
    int frame = 0;
    static const int ANIMATION_FRAMES = 2;
    static const int ANIMATION_SPEED = 8;

    //Sprite
    static const int spriteWidth = 15;
    static const int spriteHeigth = 15;
    int COLOR;

    SDL_Rect* sprites[6][ANIMATION_FRAMES];
    SDL_Rect* dead_sprite[4];
    SDLContext* context;
};


#endif //GAMETEST_SDLGHOST_H
