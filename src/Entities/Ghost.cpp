//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"

using namespace std;

Ghost::Ghost(float posX, float posY,float speed) : MovingEntity(posX, posY,speed){
    this->type = GHOST;
    this->STATE = DIR_DOWN;
}
