//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"

class Ghost : public MovingEntity {

public:
    Ghost(int posX, int posY);
    void move(int deltaX,int deltaY) override ;
    virtual void visualize()= 0;
};


#endif //GAMETEST_GHOST_H
