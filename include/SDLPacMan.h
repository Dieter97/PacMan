//
// Created by dieter on 6/03/18.
//

#ifndef GAMETEST_SDLPACMAN_H
#define GAMETEST_SDLPACMAN_H


#include "PacMan.h"
#include "SDLContext.h"

class SDLPacMan : public PacMan{
public:
    SDLPacMan(int posX, int posY, int speed, SDLContext *context);

    void visualize() override;

private:
    //Animation
    int frame = 0;
    static const int ANIMATION_FRAMES = 3;
    static const int ANIMATION_SPEED = 8;

    //Sprite
    static const int spriteWidth = 15;
    static const int spriteHeigth = 15;
    static const int SPRITE_SCALE = 3;

    SDL_Rect* sprites[6][ANIMATION_FRAMES];
    SDLContext* context;

};


#endif //GAMETEST_SDLPACMAN_H
