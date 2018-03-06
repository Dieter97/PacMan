//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_MOVINGENTITY_H
#define GAMETEST_MOVINGENTITY_H


#include "Entity.h"

class MovingEntity : public Entity {
protected:
    int direction;
    int speed;
public:
    MovingEntity(int posX, int posY, int speed);

public:
    virtual void move(int direction) = 0;
};


#endif //GAMETEST_MOVINGENTITY_H
