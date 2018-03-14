//
// Created by dieter on 7/03/18.
//

#include "../../include/SDLTile.h"

SDLTile::SDLTile( float posX, float posY, int type, int color, SDLContext *context)
        : Tile(posX, posY,type) {
    this->context = context;
    this->COLOR = color;

    int spriteY = 128 + ((TILETYPE-(TILETYPE%6))/6)*spriteHeigth  ;
    int spriteX = 6 +(((TILETYPE%6)+(COLOR*6))*spriteWidth);

    sprite = new SDL_Rect();
    sprite->x = spriteX;
    sprite->y = spriteY;
    sprite->w = spriteWidth;
    sprite->h = spriteHeigth;

}

void SDLTile::visualize() {
    int SDLPosX = (int)floorf((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR())))+context->getX_offset();;
    int SDLPosY = (int) floorf((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();;
    int SDLHeigth = (int)ceilf((float)(spriteWidth * context->getSCALE_FACTOR()));
    int SDLWidth = (int)ceilf((float)((spriteHeigth * context->getSCALE_FACTOR())));

    SDL_Rect position = {SDLPosX,SDLPosY,SDLWidth,SDLHeigth};
    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), sprite , &position, 0.0, nullptr, SDL_FLIP_NONE);
}

void SDLTile::setTILETYPE(int type) {
    Tile::setTILETYPE(type);
    int spriteY = 128 + ((TILETYPE-(TILETYPE%6))/6)*spriteHeigth  ;
    int spriteX = 6 +(((TILETYPE%6)+(COLOR*6))*spriteWidth);

    sprite = new SDL_Rect();
    sprite->x = spriteX;
    sprite->y = spriteY;
    sprite->w = spriteWidth;
    sprite->h = spriteHeigth;
}
