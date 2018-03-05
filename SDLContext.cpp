//
// Created by dieter on 05/03/18.
//

#include "SDLContext.h"

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

SDLContext::SDLContext(SDL_Renderer *renderer, int windowHeigth, int windowWidth) : renderer(renderer),
                                                                                    windowHeigth(windowHeigth),
                                                                                    windowWidth(windowWidth) {}
