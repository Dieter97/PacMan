//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_FACTORY_H
#define GAMETEST_FACTORY_H


#include "Ghost.h"

class Factory {
public:
    enum Events
    {
        KEY_PRESS_QUIT = 0,
        KEY_PRESS_SURFACE_DEFAULT = 1,
        KEY_PRESS_SURFACE_UP = 2,
        KEY_PRESS_SURFACE_DOWN = 3,
        KEY_PRESS_SURFACE_LEFT = 4,
        KEY_PRESS_SURFACE_RIGHT = 5,
        KEY_PRESS_SURFACE_TOTAL
    };
public:
    virtual Ghost* createGhost() = 0;
    virtual bool initDisplay() = 0;
    virtual void close() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
    virtual int getEvent() = 0;
};


#endif //GAMETEST_FACTORY_H
