//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"
#include "../../include/Blinky.h"

using namespace std;

Ghost::Ghost(float posX, float posY,float speed) : MovingEntity(posX, posY,speed){
    this->type = GHOST;
    this->DIRECTION = DIR_UP;
    this->STATE = DIR_UP;
    this->MODE = SCATTERING;
    this->brain = nullptr;
}

int Ghost::getNextDirection() {
    return this->DIRECTION = brain->getNextDirection(this->posX,this->posY,this->MODE);
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

void Ghost::setMODE(int mode) {
    Ghost::MODE = mode;
}

void Ghost::setBrain(AI *brain) {
    Ghost::brain = brain;
}
