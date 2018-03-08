//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"

class Ghost : public MovingEntity {

public:
    Ghost(int posX, int posY,int width,int heigth,int speed);
};


#endif //GAMETEST_GHOST_H
