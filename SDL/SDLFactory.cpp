//
// Created by dieter on 26/02/18.
//

#include "../include/SDLFactory.h"
#include "../include/SDLGhost.h"
#include "../include/SDLEvent.h"
#include "../include/SDLPacMan.h"

Ghost *SDLFactory::createGhost(int posX, int posY,int speed,int color) {
    return new SDLGhost(posX, posY,speed,color, context);
}

PacMan *SDLFactory::createPacMan(int posX, int posY, int speed) {
    return new SDLPacMan(posX, posY,speed, context);
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
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
                } else {
                    context = new SDLContext(gRenderer, height, width);
                }
            }
        }
    }

    return success;
}

bool SDLFactory::loadMedia() {
    //Loading success flag
    bool success = true;
    SDL_Texture *texture;
    SDL_Surface *loadedSurface = IMG_Load("../resources/sprites.png");
    if (loadedSurface == nullptr) {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        success = false;
    } else {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 128, 0, 128));
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (texture == nullptr) {
            std::cout << "Unable to create texture from! SDL Error: " << SDL_GetError() << std::endl;
            success = false;
        }else{
            context->setSpriteSheet(texture);
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
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

Event *SDLFactory::createEventSystem() {
    return new SDLEvent();
}
