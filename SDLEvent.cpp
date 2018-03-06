//
// Created by dieter on 05/03/18.
//

#include <SDL_events.h>
#include "SDLEvent.h"
#include "Types.h"


int SDLEvent::getEvent() {
    SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            return KEY_PRESS_QUIT;
        } else {
            if (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        return KEY_PRESS_SURFACE_UP;
                    case SDLK_DOWN:
                        return KEY_PRESS_SURFACE_DOWN;

                    case SDLK_LEFT:
                        return KEY_PRESS_SURFACE_LEFT;

                    case SDLK_RIGHT:
                        return KEY_PRESS_SURFACE_RIGHT;
                    default:
                        return KEY_PRESS_SURFACE_DEFAULT;
                }
            }
        }

}
