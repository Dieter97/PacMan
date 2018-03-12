//
// Created by dieter on 7/03/18.
//

#include "../../include/Tile.h"
#include "../../include/Types.h"


Tile::Tile(int posX, int posY, int tileType) : Entity(posX, posY){
    this->TILETYPE = tileType;
    this->type = TILE;
}

Tile::Tile() {
    TILETYPE = 0;
}

int Tile::getTILETYPE() const {
    return TILETYPE;
}

void Tile::setTILETYPE(int TILETYPE) {
    Tile::TILETYPE = TILETYPE;
}

