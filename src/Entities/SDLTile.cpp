//
// Created by dieter on 7/03/18.
//

#include "../../include/SDLTile.h"

SDLTile::SDLTile( int posX, int posY, int type, int color, SDLContext *context)
        : Tile(posX, posY, type) {
    this->context = context;
    this->COLOR = color;

    int spriteY = 296 + ((TILETYPE-(TILETYPE%6))/6)*spriteHeigth  ;
    int spriteX = 61 +(((TILETYPE%6)+(COLOR*6))*spriteWidth);

    sprite = new SDL_Rect();
    sprite->x = spriteX;
    sprite->y = spriteY;
    sprite->w = spriteWidth;
    sprite->h = spriteHeigth;

}

void SDLTile::visualize() {
    SDL_Rect position = {posX, posY, spriteHeigth * SPRITE_SCALE, spriteWidth * SPRITE_SCALE};
    SDL_RenderCopyEx(context->getRenderer(), context->getSpriteSheet(), sprite , &position, 0.0, nullptr, SDL_FLIP_NONE);
}
