//
// Created by dieter on 05/03/18.
//

#include <cmath>
#include "../../include/Entity.h"

Entity::Entity(float posX, float posY) : posX(posX), posY(posY){
    width = 1;
    heigth = 1;
}

float Entity::getPosX() const {
    return posX;
}

void Entity::setPosX(float posX) {
    this->posX = posX;
}

float Entity::getPosY() const {
    return posY;
}

void Entity::setPosY(float posY) {
    this->posY = posY;
}

Entity::Entity() {
    posX = 0;
    posY = 0;
}

bool Entity::collision(const Entity *e) {
   //The sides of the rectangles

    float mid_xA = this->getPosX() + 0.5f;
    float mid_yA = this->getPosY() + 0.5f;
    float leftA = mid_xA - this->width/2;
    float rightA = mid_xA + this->width/2;
    float topA = mid_yA - this->heigth/2;
    float bottomA = mid_yA + this->heigth/2;

    float mid_xB = e->getPosX() + 0.5f;
    float mid_yB = e->getPosY() + 0.5f;
    float leftB = mid_xB - e->width/2;
    float rightB = mid_xB + e->width/2;
    float topB = mid_yB - e->heigth/2;
    float bottomB = mid_yB + e->heigth/2;

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
    return true;/*
    bool result_floor,result_ceil;
    result_floor = ((e->getPosY()) == (this->getPosY()) && (e->getPosX()) == (this->getPosX()));
    result_ceil = (ceilf(e->getPosY()) == ceilf(this->getPosY()) && ceilf(e->getPosX()) == ceilf(this->getPosX()));
    return result_ceil;// || result_floor;*/
}

int Entity::getType() const {
    return type;
}

void Entity::setType(int type) {
    Entity::type = type;
}

float Entity::getWidth() const {
    return width;
}

void Entity::setWidth(float width) {
    Entity::width = width;
}

float Entity::getHeigth() const {
    return heigth;
}

void Entity::setHeigth(float heigth) {
    Entity::heigth = heigth;
}

