//
// Created by dieter on 09/06/18.
//

#include <iostream>
#include "../../include/SDLButton.h"

SDLButton::SDLButton(float posX, float posY, std::string string, int fontSize, Function action,
                     SDLContext *context) : Button(posX,posY,string,fontSize,action) {
    SDLButton::context = context;
}

SDLButton::SDLButton(float posX, float posY, SDLContext *context) : Button(posX,posY){
    SDLButton::context = context;
}

/**
 * SDL implementation of the visualisation
 */
void SDLButton::visualize() {
    if(!visible){
        return;
    }
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(context->getFont(), this->text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(context->getRenderer(), surface);

    long length = this->text.length();

    SDL_Rect Message_rect; //create a rect
    Message_rect.x = (int)floorf((float)(posX * context->getTilewidth() * (context->getSCALE_FACTOR()))) + context->getX_offset();
    Message_rect.y = (int) floorf((float)(posY * context->getTileHeigth() * (context->getSCALE_FACTOR())))+context->getY_offset();
    Message_rect.w = (int)floor(0.6*length*fontSize*context->getSCALE_FACTOR());
    Message_rect.h = (int)floor(0.6*fontSize*context->getSCALE_FACTOR());
    SDL_RenderCopy(context->getRenderer(), texture, nullptr, &Message_rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    //Check if mouse is over the button
    int x,y;
    SDL_GetMouseState(&x, &y);
    if( (x > Message_rect.x && (Message_rect.x + Message_rect.w) > x) &&
            (y > Message_rect.y && (Message_rect.y + Message_rect.h) > y)){
        if(!selected){
            this->select();
        }
    }else{
        if(selected){
            this->unselect();
        }
    }
}

