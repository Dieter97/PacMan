//
// Created by dieter on 05/03/18.
//

#include "../../include/MovingEntity.h"
#include "../../include/Types.h"

MovingEntity::MovingEntity(float posX, float posY,float speed) : Entity(posX, posY) {
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


void MovingEntity::pushBack(){
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
    }
}

void MovingEntity::checkMapBounds(int mapWidth, int mapHeigth) {
    if(this->getPosX() > mapWidth){
        this->setPosX(-1);
    }
    if(this->getPosX() < -1){
        this->setPosX(mapWidth);
    }
    if(this->getPosY() > mapHeigth){
        this->setPosY(-1);
    }
    if(this->getPosY() < -1){
        this->setPosY(mapHeigth);
    }
}
