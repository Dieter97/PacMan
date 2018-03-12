//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"

class Ghost : public MovingEntity {

public:
    Ghost(float posX, float posY,float speed);
};


#endif //GAMETEST_GHOST_H
