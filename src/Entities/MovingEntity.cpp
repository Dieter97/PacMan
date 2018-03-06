//
// Created by dieter on 05/03/18.
//

#include "../../include/MovingEntity.h"

MovingEntity::MovingEntity(int posX, int posY,int speed) : Entity(posX, posY) {
    this->speed = speed;
}
