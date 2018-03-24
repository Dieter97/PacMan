//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_SDLTEXTVIEW_H
#define GAMETEST_SDLTEXTVIEW_H


#include "SDLContext.h"
#include "TextView.h"
#include <string>

class SDLTextView : public TextView {
private:
    SDLContext* context;
public:
    SDLTextView(float posX, float posY,SDLContext* context);
    SDLTextView(float posX, float posY,std::string string,int fontSize,SDLContext* context);
    void visualize() override ;
};


#endif //GAMETEST_SDLTEXTVIEW_H
