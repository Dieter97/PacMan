//
// Created by dieter on 26/02/18.
//

#include "SDLFactory.h"
#include "SDLGhost.h"

Ghost *SDLFactory::createGhost() {
    return new SDLGhost(height,width,gRenderer);
}

SDLFactory::~SDLFactory() {
    close();
}


bool SDLFactory::initDisplay() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("GameTest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height, width,
                                   SDL_WINDOW_SHOWN);
        if (gWindow == nullptr) {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        } else {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if (gRenderer == NULL) {
                std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
                success = false;
            } else {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
                    success = false;
                }
            }
        }
    }

    return success;
}

void SDLFactory::close() {
    //Free loaded image
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


void SDLFactory::render() {
    //Update screen
    SDL_RenderPresent(gRenderer);
}

void SDLFactory::clear() {
    //Clear screen
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(gRenderer);
}

int SDLFactory::getEvent() {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
        return KEY_PRESS_QUIT;
    } else {
        if (e.type == SDL_KEYDOWN) {
            //Select surfaces based on key press
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    return KEY_PRESS_SURFACE_UP;
                case SDLK_DOWN:
                    return KEY_PRESS_SURFACE_DOWN;

                case SDLK_LEFT:
                    return KEY_PRESS_SURFACE_LEFT;

                case SDLK_RIGHT:
                    return KEY_PRESS_SURFACE_RIGHT;

                default:
                    return KEY_PRESS_SURFACE_DEFAULT;
            }

        }
    }
}





