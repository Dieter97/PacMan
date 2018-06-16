//
// Created by dieter on 05/03/18.
//

#include <cmath>
#include "../../include/logic/MovingEntity.h"
#include "../../include/Types.h"
using namespace logic;

MovingEntity::MovingEntity(float posX, float posY,float speed) : Entity(posX, posY) {
    this->speed = speed;
    this->spawnX = posX;
    this->spawnY = posY;
}

/**
 * Moves the entity in the given direction and saves the direction based on the speed
 * @param direction, the wanted direction
 */
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

/**
 * Moves the entity in the wanted direction based on the speed
 */
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

/**
 * Moves the player back its speed
 */
void MovingEntity::pushBack(){
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

/**
 * Checks is the entity is still beteen the play area boundries and teleports to the otherside if out of the map
 * @param mapWidth
 * @param mapHeigth
 */
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

int MovingEntity::getDIRECTION() const {
    return DIRECTION;
}

float MovingEntity::getSpawnX() const {
    return spawnX;
}

float MovingEntity::getSpawnY() const {
    return spawnY;
}

float MovingEntity::getSpeed() const {
    return speed;
}
