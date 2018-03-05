//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_MOVINGENTITY_H
#define GAMETEST_MOVINGENTITY_H


#include "Entity.h"

class MovingEntity : public Entity {
public:
    MovingEntity(int posX, int posY);

public:
    virtual void move(int deltaX,int deltaY) = 0;
};


#endif //GAMETEST_MOVINGENTITY_H
