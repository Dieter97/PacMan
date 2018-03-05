//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "Ghost.h"

using namespace std;

void Ghost::move(int deltaX,int deltaY) {
    //TODO CREATE VECTOR MOVEMENT SYSTEM with acceleration and direction
    posX = posX + deltaX;
    posY = posY + deltaY;
}

Ghost::Ghost(int posX, int posY) : MovingEntity(posX, posY){

}
