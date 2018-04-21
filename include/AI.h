//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_AI_H
#define GAMETEST_AI_H


#include "Map.h"
#include "MovingEntity.h"

class AI {
protected:
    Map* map;
    int spawnX;
    int spawnY;
    MovingEntity* target;
public:
    AI(Map* m,int x, int y,MovingEntity* t);
    virtual int getNextDirection(float posX, float posY, int mode) = 0;
};


#endif //GAMETEST_AI_H
