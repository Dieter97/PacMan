//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include <SDL_image.h>
#include "SDLGhost.h"

using namespace std;

void SDLGhost::visualize() {
    //cout << "I'm a SDL Ghost" << endl;
    // Create render position and render
    SDL_Rect position = {x, y, 47, 47};
    SDL_RenderCopyEx(renderer, texture, nullptr, &position, 0.0, nullptr, SDL_FLIP_NONE);
}

SDLGhost::SDLGhost(SDL_Renderer *renderer) {
    cout << "Creating SDLGhost" << endl;
    SDLGhost::renderer = renderer;
    string path = "../resources/main.png";
    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        cout <<  "Unable to load image! SDL_image Error: " <<  IMG_GetError() << endl;
    }
    else
    {
        //Color key image
        SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        if( texture == nullptr )
        {
            cout <<  "Unable to create texture from! SDL Error: " << SDL_GetError() << endl;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }
}