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
    int name;
public:
    Ghost(float posX, float posY,float speed,int name);
    //void setAI(Entity* target,Map* map);
    int getNextDirection();
    int getSTATE() const;
    void setSTATE(int STATE);
    void setBrain(AI *brain);
    int getMODE() const;
    void setMODE(int mode);
    AI *getBrain() const;
    int getName() const;
    void setName(int name);
    float getTargetX();
    float getTargetY();

};


#endif //GAMETEST_GHOST_H
