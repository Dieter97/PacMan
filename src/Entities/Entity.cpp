//
// Created by dieter on 05/03/18.
//

#include "../../include/Entity.h"

Entity::Entity(int posX, int posY) : posX(posX), posY(posY) {
}

int Entity::getPosX() const {
    return posX;
}

void Entity::setPosX(int posX) {
    Entity::posX = posX;
}

int Entity::getPosY() const {
    return posY;
}

void Entity::setPosY(int posY) {
    Entity::posY = posY;
}

Entity::Entity() {
    posX = 0;
    posY = 0;
}
