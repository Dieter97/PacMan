//
// Created by dieter on 6/03/18.
//

#ifndef GAMETEST_SDLPACMAN_H
#define GAMETEST_SDLPACMAN_H


#include "../logic/PacMan.h"
#include "SDLContext.h"

namespace SDL {
    class SDLPacMan : public logic::PacMan {
    public:
        SDLPacMan(float posX, float posY, float speed, SDLContext *context);

        void visualize() override;

    private:
        //Animation
        int frame = 0;
        static const int ANIMATION_FRAMES = 3;
        static const int ANIMATION_SPEED = 8;

        //Sprite
        static const int spriteWidth = 15;
        static const int spriteHeigth = 15;

        SDL_Rect *sprites[6][ANIMATION_FRAMES];
        SDLContext *context;

    };
}

#endif //GAMETEST_SDLPACMAN_H
