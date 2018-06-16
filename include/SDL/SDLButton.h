//
// Created by dieter on 09/06/18.
//

#ifndef GAMETEST_SDLBUTTON_H
#define GAMETEST_SDLBUTTON_H


#include "../logic/Button.h"
#include "SDLContext.h"

namespace SDL {
    class SDLButton : public logic::Button {
    private:
        SDLContext *context;
    public:
        SDLButton(float posX, float posY, SDLContext *context);

        SDLButton(float posX, float posY, std::string string, int fontSize, logic::Function action, SDLContext *context);

        void visualize() override;
    };
}


#endif //GAMETEST_SDLBUTTON_H
