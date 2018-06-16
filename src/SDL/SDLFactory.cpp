//
// Created by dieter on 26/02/18.
//

#include <SDL_ttf.h>
#include "../../include/SDLFactory.h"
#include "../../include/SDLGhost.h"
#include "../../include/SDLEvent.h"
#include "../../include/SDLPacMan.h"
#include "../../include/SDLMap.h"
#include "../../include/SDLTextView.h"
#include "../../include/SDLTimer.h"
#include "../../include/SDLButton.h"

/**
 * Initializes and SDL window with given parameters and using Vsync to force 60fps
 * @param mapWidth
 * @param mapHeight
 * @return, bool, success = true, fail = false
 */
bool SDLFactory::initDisplay(int mapWidth ,int mapHeight) {
    //Initialization flag
    bool success = true;

    int usedWindowWidth = WINDOW_WIDTH;
    int usedWindowHeigth = WINDOW_HEIGTH;
    int x_off=0, y_off=0;

    float scale1 = (float)WINDOW_HEIGTH/((float)tileHeight*(float)mapHeight);
    float scale2 = (float)WINDOW_WIDTH/((float)tileWidth*(float)mapWidth);

    if(scale1 < scale2){
        usedWindowWidth = (int)(scale1 * tileWidth * mapWidth);
        x_off = (WINDOW_WIDTH - usedWindowWidth)/2;
    }else{
        usedWindowHeigth = (int)(scale2 * tileHeight * mapHeight);
        y_off = (WINDOW_HEIGTH - usedWindowHeigth)/2;
    }

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


                    if(scale1 < scale2){
                        context = new SDLContext(gRenderer, WINDOW_WIDTH, WINDOW_HEIGTH,tileWidth,tileHeight,
                                                 scale1,x_off,y_off);
                        std::cout << "Using scale factor: " << scale1 << std::endl;
                    }else{
                        context = new SDLContext(gRenderer, WINDOW_WIDTH, WINDOW_HEIGTH,tileWidth,tileHeight,
                                                 scale2,x_off,y_off);
                        std::cout << "Using scale factor: " << scale2 << std::endl;
                    }
                    //SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);

                    if (TTF_Init() < 0) {
                        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
                    }else{
                        this->loadMedia();
                    }
                }
            }
        }
    }

    return success;
}

/**
 * Loads the sprite files and fonts
 * (and sounds)
 * @return bool, success = true, fail = false
 */
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

    gFont = TTF_OpenFont("../resources/pixel.ttf", 24);
    if(gFont == nullptr){
        std::cout << "Unable to load ttf! SDL_ttf Error: " << TTF_GetError() << std::endl;
        success = false;
    } else{
        context->setFont(gFont);
    }

    return success;
}

Ghost *SDLFactory::createGhost(float posX, float posY, float speed, int color) {
    return new SDLGhost(posX, posY, speed, color, context);
}

PacMan *SDLFactory::createPacMan(float posX, float posY, float speed) {
    return new SDLPacMan(posX, posY, speed, context);
}

Tile *SDLFactory::createTile(float posX, float posY, int tileType, int tileColor) {
    return new SDLTile(posX, posY, tileType, tileColor, context);
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

TextView *SDLFactory::createTextView(float posX, float posY, std::string string, int fontSize) {
    return new SDLTextView(posX,posY,string,fontSize,this->context);
}

Timer *SDLFactory::createTimer() {
    return new SDLTimer();
}

Button *SDLFactory::createButton(float posX, float posY, std::string string, int fontSize, Function action) {
    return new SDLButton(posX, posY, string, fontSize, action,this->context);
}

SDLFactory::~SDLFactory() {
    this->close();
}

/**
 * Destroys all SDL elements and media
 */
void SDLFactory::close() {
    //Free loaded image
    SDL_DestroyTexture(gTexture);
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = NULL;

    //Destroy font
    TTF_CloseFont(gFont);

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
