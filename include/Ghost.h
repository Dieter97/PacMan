//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"
#include "AI.h"

class Ghost : public MovingEntity {
private:
    //GreedyAI *brain;
public:
    Ghost(float posX, float posY,float speed);
    //void setAI(Entity* target,Map* map);
    int getNextDirection();
};


#endif //GAMETEST_GHOST_H
