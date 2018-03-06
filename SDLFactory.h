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
    int height=1024;
    int width=500;

public:
    Ghost* createGhost(int posX,int posY,int speed) override;
    Event* createEventSystem() override ;
    bool initDisplay() override ;
    bool loadMedia() override ;
    void close() override;
    void render() override ;
    void clear() override ;
    virtual ~SDLFactory();
};


#endif //GAMETEST_SDLFACTORY_H
