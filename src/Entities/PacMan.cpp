//
// Created by dieter on 6/03/18.
//

#include "../../include/PacMan.h"
#include "../../include/Types.h"

PacMan::PacMan(int posX, int posY, int speed) : MovingEntity(posX, posY, speed) {
    this->type = PACMAN;
    this->STATE = DIR_LEFT;
}

