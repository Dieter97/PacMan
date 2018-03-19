//
// Created by dieter on 05/03/18.
//

#include <cmath>
#include "../../include/MovingEntity.h"
#include "../../include/Types.h"

MovingEntity::MovingEntity(float posX, float posY,float speed) : Entity(posX, posY) {
    this->speed = speed;
    this->hitBoxOffset = (int)(speed-0.125f)*10+94;
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

void MovingEntity::pushBack(){
    float roundX = roundf(posX);
    float roundY = roundf(posY);
    switch (this->STATE){
        case DIR_UP:
            posY = posY + speed;
            break;
        case DIR_DOWN:
            posY = posY - speed;
            break;
        case DIR_LEFT:
            posX = posX + speed;
            break;
        case DIR_RIGHT:
            posX = posX - speed;
            break;
        default:
            break;
    }/*
    if(posX+0.05f > roundX || posX-0.05f < roundX){
        posX = roundX;
    }
    if(posY+0.05f > roundX || posY-0.05f < roundX){
        posY = roundY;
    }*/
}

void MovingEntity::checkMapBounds(int mapWidth, int mapHeigth) {
    if(this->getPosX() > mapWidth){
        this->setPosX(0);
    }
    if(this->getPosX() < 0){
        this->setPosX(mapWidth);
    }
    if(this->getPosY() > mapHeigth){
        this->setPosY(0);
    }
    if(this->getPosY() < 0){
        this->setPosY(mapHeigth);
    }
}
