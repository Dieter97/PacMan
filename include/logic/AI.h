//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_AI_H
#define GAMETEST_AI_H


#include "Map.h"
#include "MovingEntity.h"
namespace logic {
    class AI {
    protected:
        Map *map;
        int spawnX;
        int spawnY;
        int doorX;
        int doorY;
        MovingEntity *target;
    public:
        AI(Map *m, int x, int y, MovingEntity *t);

        float getTargetX();

        float getTargetY();

        virtual int getNextDirection(float posX, float posY, int mode) = 0;
    };
}


#endif //GAMETEST_AI_H
