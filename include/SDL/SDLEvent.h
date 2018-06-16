//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_SDLEVENT_H
#define GAMETEST_SDLEVENT_H


#include "../logic/Event.h"

namespace SDL {
    class SDLEvent : public logic::Event {
    private:
        //Event handler
        SDL_Event e;
    public:
        int getEvent() override;

    };
}


#endif //GAMETEST_SDLEVENT_H
