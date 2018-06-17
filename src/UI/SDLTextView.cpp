//
// Created by dieter on 24/03/18.
//

#include "../../include/SDL/SDLTextView.h"
using namespace SDL;

SDLTextView::SDLTextView(float posX, float posY,SDLContext* context) : TextView(posX,posY) {
    this->context = context;
}

SDLTextView::SDLTextView(float posX, float posY, std::string string,int fontSize,SDLContext* context) :
        TextView(posX,posY,string,fontSize) {
    this->context = context;
}

/**
 * SDL implementation of the visualisation
 */
void SDLTextView::visualize() {
    if(!visible){
        return;
    }
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(context->getFont(), this->text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(context->getRenderer(), surface);

    long length = this->text.length();

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = (int)std::floor((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR()))) + context->getX_offset();
    Message_rect.y = (int) std::floor((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();
    Message_rect.w = (int)std::floor(0.6*length*fontSize*context->getSCALE_FACTOR());
    Message_rect.h = (int)std::floor(0.6*fontSize*context->getSCALE_FACTOR());
    SDL_RenderCopy(context->getRenderer(), texture, nullptr, &Message_rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
