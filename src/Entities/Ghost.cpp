//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "../../include/Ghost.h"
#include "../../include/Types.h"

using namespace std;

Ghost::Ghost(int posX, int posY,int speed) : MovingEntity(posX, posY,speed){
    STATE = DIR_DOWN;
}
