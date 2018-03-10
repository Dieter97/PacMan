//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"

using namespace std;

Ghost::Ghost(int posX, int posY,int width,int heigth,int speed) : MovingEntity(posX, posY,width,heigth,speed){
    this->type = GHOST;
    this->STATE = DIR_DOWN;
}
