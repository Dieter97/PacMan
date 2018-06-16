//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"
#include "../../include/Blinky.h"

using namespace std;

Ghost::Ghost(float posX, float posY,float speed,int name) : MovingEntity(posX, posY,speed){
    this->type = GHOST;
    this->DIRECTION = DIR_UP;
    this->STATE = DIR_UP;
    this->MODE = HOME;
    this->brain = nullptr;
    this->name = name;
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

AI *Ghost::getBrain() const {
    return brain;
}

int Ghost::getName() const {
    return name;
}

void Ghost::setName(int name) {
    Ghost::name = name;
}

float Ghost::getTargetX() {
    return Ghost::brain->getTargetX();
}

float Ghost::getTargetY() {
    return Ghost::brain->getTargetY();
}

void Ghost::checkTimer() {
    if(timer->getTicks() > waitTime){
        this->setMODE(LEAVE);
        this->timer->stop();
    }
}

void Ghost::startTimer(int length) {
    waitTime = length;
    timer->stop();
    timer->start();
}

void Ghost::stopTimer() {
    timer->stop();
}

void Ghost::pauseTimer() {
    timer->pause();
}

void Ghost::unpauseTimer() {
    timer->unpause();
}

void Ghost::teleportToSpawn() {
    this->posX = this->spawnX;
    this->posY = this->spawnY;
}

