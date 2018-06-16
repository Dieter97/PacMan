//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_SDLTEXTVIEW_H
#define GAMETEST_SDLTEXTVIEW_H


#include "SDLContext.h"
#include "../logic/TextView.h"
#include <string>

namespace SDL {
    class SDLTextView : public logic::TextView {
    private:
        SDLContext *context;
    public:
        SDLTextView(float posX, float posY, SDLContext *context);

        SDLTextView(float posX, float posY, std::string string, int fontSize, SDLContext *context);

        void visualize() override;
    };
}


#endif //GAMETEST_SDLTEXTVIEW_H
