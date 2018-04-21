//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"
#include "../../include/GreedyAI.h"

using namespace std;

Ghost::Ghost(float posX, float posY,float speed,AI* ai) : MovingEntity(posX, posY,speed){
    this->type = GHOST;
    this->DIRECTION = DIR_UP;
    this->STATE = DIR_UP;
    this->MODE = SCATTERING;
    this->brain = ai;
}

int Ghost::getNextDirection(float targetX, float targetY) {
    return this->DIRECTION = brain->getNextDirection(targetX,targetY,this->MODE);
}

int Ghost::getSTATE() const {
    return STATE;
}

void Ghost::setSTATE(int STATE) {
    Ghost::STATE = STATE;
}

int Ghost::getMODE() const {
    return MODE;
}
