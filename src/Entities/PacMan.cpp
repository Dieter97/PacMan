//
// Created by dieter on 6/03/18.
//

#include "../../include/logic/PacMan.h"
#include "../../include/Types.h"
using namespace logic;

PacMan::PacMan(float posX, float posY, float speed) : MovingEntity(posX, posY, speed) {
    this->type = PACMAN;
    this->DIRECTION = DIR_LEFT;
    this->STATE = DIR_LEFT;
}

int PacMan::getSTATE() const {
    return STATE;
}

void PacMan::setSTATE(int STATE) {
    PacMan::STATE = STATE;
}

