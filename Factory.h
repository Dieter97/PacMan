//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_FACTORY_H
#define GAMETEST_FACTORY_H


#include "Ghost.h"
#include "Event.h"

class Factory {
public:

public:
    virtual Ghost* createGhost(int posX,int posY) = 0;
    virtual Event* createEventSystem() = 0;
    virtual bool initDisplay() = 0;
    virtual void close() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
};


#endif //GAMETEST_FACTORY_H
