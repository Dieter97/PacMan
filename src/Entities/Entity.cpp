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
    width = 0;
    heigth = 0;
}

bool Entity::collision(const Entity *e) {
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = this->posX;
    rightA = this->posX + this->width;
    topA = this->posY;
    bottomA = this->posY + this->heigth;

    //Calculate the sides of rect B
    leftB = e->posX;
    rightB = e->posX + e->width;
    topB = e->posY;
    bottomB = e->posY + e->heigth;


    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

int Entity::getType() const {
    return type;
}

void Entity::setType(int type) {
    Entity::type = type;
}
