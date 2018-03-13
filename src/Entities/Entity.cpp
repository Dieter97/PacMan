//
// Created by dieter on 05/03/18.
//

#include <cmath>
#include "../../include/Entity.h"

Entity::Entity(float posX, float posY) : posX(posX), posY(posY){
}

float Entity::getPosX() const {
    return posX;
}

void Entity::setPosX(float posX) {
    Entity::posX = posX;
}

float Entity::getPosY() const {
    return posY;
}

void Entity::setPosY(float posY) {
    Entity::posY = posY;
}

Entity::Entity() {
    posX = 0;
    posY = 0;
}

bool Entity::collision(const Entity *e) {
    //The sides of the rectangles
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

/*
    //Calculate the sides of rect A
    leftA = floorf(this->getPosX());
    rightA = floorf(this->getPosX()) + this->width;
    topA = floorf(this->getPosY());
    bottomA = floorf(this->getPosY()) + this->heigth;

    //Calculate the sides of rect B
    leftB = floorf(e->getPosX());
    rightB = floorf(e->getPosX()) + e->width;
    topB = floorf(e->getPosY());
    bottomB = floorf(e->getPosY()) + e->heigth;
*/
    //Calculate the sides of rect A
    leftA = this->getPosX();
    rightA = this->getPosX() + this->width;
    topA = this->getPosY();
    bottomA = this->getPosY() + this->heigth;

    //Calculate the sides of rect B
    leftB = e->getPosX();
    rightB = e->getPosX() + e->width;
    topB = e->getPosY();
    bottomB = e->getPosY() + e->heigth;

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

    return (floor(e->getPosY()) == floor(this->getPosY()) && floor(e->getPosX()) == floor(this->getPosX()));
}

int Entity::getType() const {
    return type;
}

void Entity::setType(int type) {
    Entity::type = type;
}
