//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLGHOST_H
#define GAMETEST_SDLGHOST_H


#include "Ghost.h"

class SDLGhost : public Ghost {

public:
    SDLGhost();

    void visualize() override;

};


#endif //GAMETEST_SDLGHOST_H
