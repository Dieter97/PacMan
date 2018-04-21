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
    Ghost(float posX, float posY,float speed);
    //void setAI(Entity* target,Map* map);
    int getNextDirection();
    int getSTATE() const;
    void setSTATE(int STATE);

    void setBrain(AI *brain);

    int getMODE() const;
    void setMODE(int mode);
};


#endif //GAMETEST_GHOST_H
