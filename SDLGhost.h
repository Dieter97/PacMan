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
    SDLGhost(int posX, int posY, SDLContext *context);

    void visualize() override;

private:
    //The final texture
    SDL_Texture* texture;
    SDLContext* context;
};


#endif //GAMETEST_SDLGHOST_H
