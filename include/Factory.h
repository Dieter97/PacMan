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

class Factory {
public:

    //Window parameters
    int WINDOW_WIDTH=995;
    int WINDOW_HEIGTH=500;

    //Tilemap parameters
    static const int TILE_HEIGTH = 8;
    static const int TILE_WIDTH = 8;
    static const int TILE_SCALE = 3;

public:
    virtual Ghost* createGhost(int posX,int posY,int speed,int color) = 0;
    virtual PacMan* createPacMan(int posX,int posY,int speed) = 0;
    virtual Tile* createTile(int posX,int posY,int tileType,int tileColor) = 0;
    virtual Event* createEventSystem() = 0;
    virtual Map* createMap(int width,int heigth) = 0;
    virtual bool initDisplay(int windowWidth,int windowHeight) = 0;
    virtual bool loadMedia() = 0;
    virtual void close() = 0;
    virtual void render() = 0;
    virtual void clear() = 0;
};


#endif //GAMETEST_FACTORY_H
