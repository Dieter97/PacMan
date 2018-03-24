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
    this->DIRECTION = DIR_UP;
    this->STATE = DIR_UP;
}
/*
void Ghost::setAI(Entity *target, Map *map) {
    this->brain = new GreedyAI(target,map);
}*/

int Ghost::getNextDirection() {
   (this->DIRECTION = rand() % 4);
    return this->DIRECTION;
}

int Ghost::getSTATE() const {
    return STATE;
}

void Ghost::setSTATE(int STATE) {
    Ghost::STATE = STATE;
}