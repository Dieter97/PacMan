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

SDLContext::SDLContext(SDL_Renderer *renderer, int windowHeigth, int windowWidth,int tileWidth,int tileHeight,
                       float scale,int x_off,int y_off) :
        renderer(renderer), windowHeigth(windowHeigth), windowWidth(windowWidth),
        tilewidth(tileWidth),tileHeigth(tileHeight), SCALE_FACTOR(scale), X_offset(x_off),Y_offset(y_off){
}

SDL_Texture *SDLContext::getSpriteSheet() const {
    return spriteSheet;
}

void SDLContext::setSpriteSheet(SDL_Texture *spriteSheet) {
    SDLContext::spriteSheet = spriteSheet;
}

float SDLContext::getTilewidth() const {
    return tilewidth;
}

float SDLContext::getTileHeigth() const {
    return tileHeigth;
}

double SDLContext::getSCALE_FACTOR() const {
    return SCALE_FACTOR;
}

int SDLContext::getX_offset() const {
    return X_offset;
}

int SDLContext::getY_offset() const {
    return Y_offset;
}
