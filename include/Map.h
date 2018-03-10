//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_MAP_H
#define GAMETEST_MAP_H


#include <vector>
#include "Tile.h"
#include "SDLTile.h"

class Map {
protected:
    //Parameters of one tile
    int TILE_WIDTH;
    int TILE_HEIGHT;


    //Parameters of the entire map
    int MAP_WIDTH;
    int MAP_HEIGHT;

    Tile ***tileMap;

public:
    Map(int width,int height,int tileWidth,int tileHeigth);
    virtual void visualize() = 0;
    virtual void loadMap(int** map,int COLOR) = 0;
    bool checkCollision(Entity* e);
};


#endif //GAMETEST_MAP_H
