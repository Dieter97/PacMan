//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"
#include "AI.h"

class Ghost : public MovingEntity {
protected:
    AI *brain;
    int STATE;
    int MODE;
public:
    Ghost(float posX, float posY,float speed,AI* ai);
    //void setAI(Entity* target,Map* map);
    int getNextDirection(float targetX, float targetY);
    int getSTATE() const;
    void setSTATE(int STATE);

    int getMODE() const;
};


#endif //GAMETEST_GHOST_H
