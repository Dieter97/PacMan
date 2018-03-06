//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_SDLCONTEXT_H
#define GAMETEST_SDLCONTEXT_H


#include <SDL.h>

class SDLContext {
protected:
    int windowHeigth;
    int windowWidth;
    SDL_Renderer* renderer;
    SDL_Texture* spriteSheet;
public:
    SDL_Texture *getSpriteSheet() const;

    void setSpriteSheet(SDL_Texture *spriteSheet);

    SDLContext(SDL_Renderer *renderer, int windowHeigth, int windowWidth);

    SDL_Renderer *getRenderer() const;

    void setRenderer(SDL_Renderer *renderer);

    int getWindowHeigth() const;

    void setWindowHeigth(int windowHeigth);

    int getWindowWidth() const;

    void setWindowWidth(int windowWidth);
};


#endif //GAMETEST_SDLCONTEXT_H
