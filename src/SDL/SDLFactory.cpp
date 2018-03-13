//
// Created by dieter on 26/02/18.
//

#include "../../include/SDLFactory.h"
#include "../../include/SDLGhost.h"
#include "../../include/SDLEvent.h"
#include "../../include/SDLPacMan.h"
#include "../../include/SDLTile.h"
#include "../../include/SDLMap.h"

Ghost *SDLFactory::createGhost(float posX, float posY,float speed,int color) {
    return new SDLGhost(posX, posY,speed,color, context);
}

PacMan *SDLFactory::createPacMan(float posX, float posY, float speed) {
    return new SDLPacMan(posX, posY,speed, context);
}

Tile *SDLFactory::createTile(float posX, float posY, int tileType, int tileColor) {
    return new SDLTile(posX, posY,tileType,tileColor, context);
}

SDLFactory::~SDLFactory() {
    close();
}

bool SDLFactory::initDisplay(int mapWidth ,int mapHeight) {
    //Initialization flag
    bool success = true;
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGTH,
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

                    float scale1 = (float)WINDOW_HEIGTH/((float)tileHeight*(float)mapHeight);
                    float scale2 = (float)WINDOW_WIDTH/((float)tileWidth*(float)mapWidth);
                    if(scale1 < scale2){
                        context = new SDLContext(gRenderer, WINDOW_WIDTH, WINDOW_HEIGTH,tileWidth,tileHeight,scale1);
                        std::cout << "Using scale factor: " << scale1 << std::endl;
                    }else{
                        context = new SDLContext(gRenderer, WINDOW_WIDTH, WINDOW_HEIGTH,tileWidth,tileHeight,scale2);
                        std::cout << "Using scale factor: " << scale2 << std::endl;
                    }

                    this->loadMedia();
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
    SDL_Surface *loadedSurface = IMG_Load("../resources/sprites2.png");
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

Map *SDLFactory::createMap(int width, int height) {
    return new SDLMap(width,height,context);
}
