//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_FACTORY_H
#define GAMETEST_FACTORY_H


#include "Entities/Ghost.h"
#include "Event.h"
#include "Entities/PacMan.h"

class Factory {
public:

public:
    virtual Ghost* createGhost(int posX,int posY,int speed,int color) = 0;
    virtual PacMan* createPacMan(int posX,int posY,int speed) = 0;
    virtual Event* createEventSystem() = 0;
    virtual bool initDisplay() = 0;
    virtual bool loadMedia() = 0;
    virtual void close() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
};


#endif //GAMETEST_FACTORY_H
