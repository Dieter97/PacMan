//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"

using namespace std;

void Ghost::move(int direction) {
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

Ghost::Ghost(int posX, int posY,int speed) : MovingEntity(posX, posY,speed){
    direction = DIR_DOWN;
}
