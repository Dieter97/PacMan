//
// Created by dieter on 09/06/18.
//

#ifndef GAMETEST_SDLBUTTON_H
#define GAMETEST_SDLBUTTON_H


#include "Button.h"
#include "SDLContext.h"

class SDLButton : public Button {
private:
    SDLContext* context;
public:
    SDLButton(float posX, float posY,SDLContext* context);
    SDLButton(float posX, float posY,std::string string,int fontSize,Function action,SDLContext* context);
    void visualize() override ;
};


#endif //GAMETEST_SDLBUTTON_H
