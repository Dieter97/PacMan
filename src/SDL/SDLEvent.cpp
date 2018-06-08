//
// Created by dieter on 05/03/18.
//

#include <SDL_events.h>
#include "../../include/SDLEvent.h"
#include "../../include/Types.h"


int SDLEvent::getEvent() {
    SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            return KEY_PRESS_QUIT;
        } else {
            if (e.type == SDL_KEYDOWN) {
                //Select surfaces based on key press
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        return KEY_PRESS_UP;
                    case SDLK_DOWN:
                        return KEY_PRESS_DOWN;
                    case SDLK_LEFT:
                        return KEY_PRESS_LEFT;

                    case SDLK_RIGHT:
                        return KEY_PRESS_RIGHT;
                    case SDLK_SPACE:
                        return KEY_PRESS_SPACE;
                    case SDLK_ESCAPE:
                        return  KEY_PRESS_ESC;
                    default:
                        return KEY_PRESS_DEFAULT;
                }
            }
        }

}
