//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_SDLTILE_H
#define GAMETEST_SDLTILE_H


#include "SDLContext.h"
#include "Tile.h"

class SDLTile : public Tile {
public:
    SDLTile(float posX, float posY, int type, int color, SDLContext *context);

    void visualize() override;
    void setTILETYPE(int type) override ;

private:
    //Sprite
    static const int spriteWidth = 16;
    static const int spriteHeigth = 16;
    int COLOR;

    SDL_Rect* sprite;
    SDLContext* context;
};


#endif //GAMETEST_SDLTILE_H
