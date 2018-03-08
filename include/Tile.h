//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_TILE_H
#define GAMETEST_TILE_H


#include "Entity.h"

class Tile : public Entity {
public:

    Tile();

    Tile(int posX, int posY, int tileType);


protected:
    int TILETYPE;
public:
    int getTILETYPE() const;

    void setTILETYPE(int TILETYPE);
};


#endif //GAMETEST_TILE_H
