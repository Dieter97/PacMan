//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLFACTORY_H
#define GAMETEST_SDLFACTORY_H

#include "Factory.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"


class SDLFactory : public Factory{

private:
    //The window we'll be rendering to
    SDL_Window* gWindow;
    //The window renderer
    SDL_Renderer* gRenderer = nullptr;
    //Current displayed texture
    SDL_Texture* gTexture = nullptr;

public:
    Ghost* createGhost() override;
    bool initDisplay() override ;
    void close() override ;

protected:
    //Loads individual image as texture
    SDL_Texture* loadTexture( std::string path );
};


#endif //GAMETEST_SDLFACTORY_H
