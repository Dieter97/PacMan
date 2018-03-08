//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_SDLTILE_H
#define GAMETEST_SDLTILE_H


#include "SDLContext.h"
#include "Tile.h"

class SDLTile : public Tile {
public:
    SDLTile(int posX, int posY, int type, int color, SDLContext *context);

    void visualize() override;
private:
    //Sprite
    static const int spriteWidth = 9;
    static const int spriteHeigth = 9;
    static const int SPRITE_SCALE = 4;
    int COLOR;

    SDL_Rect* sprite;
    SDLContext* context;
};


#endif //GAMETEST_SDLTILE_H
