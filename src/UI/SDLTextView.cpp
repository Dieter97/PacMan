//
// Created by dieter on 24/03/18.
//

#include "SDLTextView.h"

SDLTextView::SDLTextView(float posX, float posY,SDLContext* context) : TextView(posX,posY) {
    this->context = context;
}

SDLTextView::SDLTextView(float posX, float posY, std::string string,int fontSize,SDLContext* context) :
        TextView(posX,posY,string,fontSize) {
    this->context = context;
}

void SDLTextView::visualize() {
    if(!visible){
        return;
    }
    SDL_Color color = {255,255,255};
    SDL_Surface* surface = TTF_RenderText_Solid(context->getFont(), this->text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(context->getRenderer(), surface);

    long length = this->text.length();

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = (int)floorf((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR())))+context->getX_offset();
    Message_rect.y = (int) floorf((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();
    Message_rect.w = (int)floor(0.6*length*fontSize*context->getSCALE_FACTOR());
    Message_rect.h = (int)floor(0.6*fontSize*context->getSCALE_FACTOR());
    SDL_RenderCopy(context->getRenderer(), texture, NULL, &Message_rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
