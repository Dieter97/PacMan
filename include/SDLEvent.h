//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_SDLEVENT_H
#define GAMETEST_SDLEVENT_H


#include "Event.h"

class SDLEvent: public Event {
private:
    //Event handler
    SDL_Event e;
public:
    int getEvent() override ;

};


#endif //GAMETEST_SDLEVENT_H
