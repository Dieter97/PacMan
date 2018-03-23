//
// Created by dieter on 6/03/18.
//

#include "../../include/PacMan.h"
#include "../../include/Types.h"

PacMan::PacMan(float posX, float posY, float speed) : MovingEntity(posX, posY, speed) {
    this->type = PACMAN;
    this->DIRECTION = DIR_LEFT;
}

void PacMan::die() {

}

