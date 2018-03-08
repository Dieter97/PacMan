//
// Created by dieter on 05/03/18.
//

#include "../../include/MovingEntity.h"
#include "../../include/Types.h"

MovingEntity::MovingEntity(int posX, int posY,int width,int height,int speed) : Entity(posX, posY,width,height) {
    this->speed = speed;
}

void MovingEntity::move(int direction) {
    this->STATE = direction;
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