//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_MOVINGENTITY_H
#define GAMETEST_MOVINGENTITY_H


#include "Entity.h"

class MovingEntity : public Entity {
protected:
    int STATE;
    int speed;
public:
    MovingEntity(int posX, int posY, int speed);

public:
    void move(int direction);

    void pushBack();
};


#endif //GAMETEST_MOVINGENTITY_H
