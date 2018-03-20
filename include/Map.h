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
    //Parameters of the entire map
    int MAP_WIDTH;
    int MAP_HEIGHT;
    Tile ***tileMap;
public:

    Map(int width,int height);
    virtual void visualize() = 0;
    virtual void loadMap(int** map,int COLOR) = 0;
    Tile ***getTileMap() const;
    int checkCollision(Entity* e);
    int getMAP_WIDTH() const;
    int getMAP_HEIGHT() const;
    bool isIntersection(int posX,int posY);
    bool isDone();
};


#endif //GAMETEST_MAP_H
