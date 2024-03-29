//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_TILE_H
#define GAMETEST_TILE_H


#include "Entity.h"

namespace logic {
    class Tile : public Entity {
    public:

        Tile();

        Tile(float posX, float posY, int tileType);

        int getTILETYPE() const;

        virtual void setTILETYPE(int TILETYPE);

    protected:
        int TILETYPE;
    };
}


#endif //GAMETEST_TILE_H
