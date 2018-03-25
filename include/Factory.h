//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_FACTORY_H
#define GAMETEST_FACTORY_H


#include "Ghost.h"
#include "Event.h"
#include "PacMan.h"
#include "Tile.h"
#include "Map.h"
#include "TextView.h"
#include "Timer.h"
#include <string>

class Factory {

public:
    virtual Ghost* createGhost(float posX,float posY,float speed,int color) = 0;
    virtual PacMan* createPacMan(float posX,float posY,float speed) = 0;
    virtual Tile* createTile(float posX,float posY,int tileType,int tileColor) = 0;
    virtual Event* createEventSystem() = 0;
    virtual Map* createMap(int width,int heigth) = 0;
    virtual bool initDisplay(int mapWidth ,int mapHeight) = 0;
    virtual bool loadMedia() = 0;
    virtual TextView* createTextView(float posX, float posY,std::string string,int fontSize) = 0;
    virtual Timer* createTimer() = 0;
    virtual void close() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
};


#endif //GAMETEST_FACTORY_H
