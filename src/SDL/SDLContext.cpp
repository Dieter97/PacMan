//
// Created by dieter on 05/03/18.
//

#include "../../include/SDLContext.h"

SDL_Renderer *SDLContext::getRenderer() const {
    return renderer;
}

void SDLContext::setRenderer(SDL_Renderer *renderer) {
    SDLContext::renderer = renderer;
}

int SDLContext::getWindowHeigth() const {
    return windowHeigth;
}

void SDLContext::setWindowHeigth(int windowHeigth) {
    SDLContext::windowHeigth = windowHeigth;
}

int SDLContext::getWindowWidth() const {
    return windowWidth;
}

void SDLContext::setWindowWidth(int windowWidth) {
    SDLContext::windowWidth = windowWidth;
}

SDLContext::SDLContext(SDL_Renderer *renderer, int windowHeigth, int windowWidth,int tileWidth,int tileHeight) :
        renderer(renderer), windowHeigth(windowHeigth), windowWidth(windowWidth), tilewidth(tileWidth),tileHeigth(tileHeight){
    SCALE_FACTOR = 2;
}

SDL_Texture *SDLContext::getSpriteSheet() const {
    return spriteSheet;
}

void SDLContext::setSpriteSheet(SDL_Texture *spriteSheet) {
    SDLContext::spriteSheet = spriteSheet;
}

int SDLContext::getTilewidth() const {
    return tilewidth;
}

int SDLContext::getTileHeigth() const {
    return tileHeigth;
}

double SDLContext::getSCALE_FACTOR() const {
    return SCALE_FACTOR;
}
