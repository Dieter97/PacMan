//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"
#include "AI.h"

class Ghost : public MovingEntity {
protected:
    //GreedyAI *brain;
    int STATE;
public:
    Ghost(float posX, float posY,float speed);
    //void setAI(Entity* target,Map* map);
    int getNextDirection();
    int getSTATE() const;
    void setSTATE(int STATE);
    void die();
};


#endif //GAMETEST_GHOST_H
