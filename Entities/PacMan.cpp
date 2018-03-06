//
// Created by dieter on 6/03/18.
//

#include "PacMan.h"
#include "../Types.h"

PacMan::PacMan(int posX, int posY, int speed) : MovingEntity(posX, posY, speed) {
    direction = DIR_DOWN;
}

void PacMan::move(int direction) {
    this->direction = direction;
    switch (direction){
        case DIR_UP:
            posY = posY - speed;
            break;
        case DIR_DOWN:
            posY = posY + speed;
            break;
        case DIR_LEFT:
            posX = posX - speed;
            break;
        case DIR_RIGHT:
            posX = posX + speed;
            break;
        default:
            break;
    }
}
