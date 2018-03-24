//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_SDLCONTEXT_H
#define GAMETEST_SDLCONTEXT_H


#include <SDL.h>
#include <SDL_ttf.h>

class SDLContext {
protected:

    //Window parameters
    int windowHeigth;
    int windowWidth;

    //Tile parameters
    float tilewidth;
    float tileHeigth;

    //Scaling
    float SCALE_FACTOR;

    int X_offset;
    int Y_offset;

    //SDL components
    SDL_Renderer* renderer;
    SDL_Texture* spriteSheet;
    TTF_Font* font;
public:
    SDL_Texture *getSpriteSheet() const;
    void setSpriteSheet(SDL_Texture *spriteSheet);
    SDLContext(SDL_Renderer *renderer, int windowHeigth, int windowWidth,int tileWidth, int tileHeigth,
               float scale,int x_off,int y_off);
    int getX_offset() const;
    int getY_offset() const;
    SDL_Renderer *getRenderer() const;
    void setRenderer(SDL_Renderer *renderer);
    int getWindowHeigth() const;
    void setWindowHeigth(int windowHeigth);
    int getWindowWidth() const;
    void setWindowWidth(int windowWidth);
    float getTilewidth() const;
    float getTileHeigth() const;
    double getSCALE_FACTOR() const;
    void setFont(TTF_Font* f);
    TTF_Font* getFont();
};


#endif //GAMETEST_SDLCONTEXT_H
