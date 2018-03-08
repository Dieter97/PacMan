//
// Created by dieter on 05/03/18.
//

#include "../../include/Entity.h"

Entity::Entity(int posX, int posY,int width,int heigth) : posX(posX), posY(posY), width(width), heigth(heigth) {
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
    width = 0;
    heigth = 0;
}
