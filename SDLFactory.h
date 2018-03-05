//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLFACTORY_H
#define GAMETEST_SDLFACTORY_H

#include "Factory.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDLContext.h"


class SDLFactory : public Factory{

private:
    //The window we'll be rendering to
    SDL_Window* gWindow;
    //The window renderer
    SDL_Renderer* gRenderer = nullptr;
    //Current displayed texture
    SDL_Texture* gTexture = nullptr;

    SDLContext* context;

    //Window parameters
    int height=640;
    int width=400;

public:
    Ghost* createGhost(int posX,int posY) override;
    Event* createEventSystem() override ;
    bool initDisplay() override ;
    void close() override;
    void render() override ;
    void clear() override ;
    virtual ~SDLFactory();
};


#endif //GAMETEST_SDLFACTORY_H
