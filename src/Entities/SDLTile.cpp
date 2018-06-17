//
// Created by dieter on 7/03/18.
//

#include "../../include/SDL/SDLTile.h"
#include "../../include/Types.h"
using namespace SDL;

SDLTile::SDLTile( float posX, float posY, int type, int color, SDLContext *context)
        : Tile(posX, posY,type) {
    this->context = context;
    this->COLOR = color;
    this->setTILETYPE(TILETYPE);
}

/**
 * SDL implementation of the visualisation
 */
void SDLTile::visualize() {
    int SDLPosX = (int) floor((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR()))) + context->getX_offset();
    int SDLPosY = (int) floor((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR()))) + context->getY_offset();
    int SDLHeigth = (int) ceil((float)(spriteWidth * context->getSCALE_FACTOR()));
    int SDLWidth = (int) ceil((float)((spriteHeigth * context->getSCALE_FACTOR())));

    SDL_Rect position = {SDLPosX, SDLPosY, SDLWidth, SDLHeigth};
    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), sprite , &position, 0.0, nullptr, SDL_FLIP_NONE);
}

/**
 * Sets the type of the tile and loads its sprite
 * @param type
 */
void SDLTile::setTILETYPE(int type) {
    Tile::setTILETYPE(type);
    int spriteY = 128 + ((TILETYPE - (TILETYPE % 6)) / 6) * spriteHeigth;
    int spriteX = 6 + (((TILETYPE % 6) + (COLOR * 6)) * spriteWidth);

    //Points are smaller to hit
    if(type == POINT_SMALL){
        this->setWidth(0.01f);
        this->setHeigth(0.01f);
    }

    sprite = new SDL_Rect();
    sprite->x = spriteX;
    sprite->y = spriteY;
    sprite->w = spriteWidth;
    sprite->h = spriteHeigth;
}
