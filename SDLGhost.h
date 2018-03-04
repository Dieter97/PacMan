//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLGHOST_H
#define GAMETEST_SDLGHOST_H


#include <SDL_render.h>
#include "Ghost.h"

class SDLGhost : public Ghost {

public:
    SDLGhost(SDL_Renderer* renderer);

    void visualize() override;

private:
    //The final texture
    SDL_Texture* texture;
    SDL_Renderer* renderer;
};


#endif //GAMETEST_SDLGHOST_H
