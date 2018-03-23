//
// Created by dieter on 05/03/18.
//

#include <cmath>
#include "../../include/MovingEntity.h"
#include "../../include/Types.h"

MovingEntity::MovingEntity(float posX, float posY,float speed) : Entity(posX, posY) {
    this->speed = speed;
}

void MovingEntity::move(int direction) {
    this->DIRECTION = direction;
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

void MovingEntity::move() {
    switch (this->DIRECTION){
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
    switch (this->DIRECTION){
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

bool MovingEntity::isChangedDir() const {
    return changedDir;
}

void MovingEntity::setChangedDir(bool changedDir) {
    MovingEntity::changedDir = changedDir;
}
