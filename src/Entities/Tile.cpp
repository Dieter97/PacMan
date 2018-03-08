//
// Created by dieter on 7/03/18.
//

#include "../../include/Tile.h"


Tile::Tile(int posX, int posY, int tileType) : Entity(posX, posY){
    this->TILETYPE = tileType;
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
