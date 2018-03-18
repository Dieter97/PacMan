//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"
#include "../../include/GreedyAI.h"

using namespace std;

Ghost::Ghost(float posX, float posY,float speed) : MovingEntity(posX, posY,speed){
    this->type = GHOST;
    this->STATE = DIR_DOWN;
    this->counter = 0;
    this->dir = DIR_DOWN;
}
/*
void Ghost::setAI(Entity *target, Map *map) {
    this->brain = new GreedyAI(target,map);
}*/

int Ghost::getNextDirection() {
    counter++;
    if(counter > 100){
        dir = rand() % 4;
        counter = 0;
    }
    return dir;
}
