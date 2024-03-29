//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


#include "MovingEntity.h"
#include "AI.h"
#include "Timer.h"

namespace logic {
    class Ghost : public MovingEntity {
    protected:
        AI *brain;
        int STATE;
        int MODE;
        int name;
        Timer *timer;
        int waitTime;
    public:
        Ghost(float posX, float posY, float speed, int name);

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

        void startTimer(int lenght);

        void stopTimer();

        void pauseTimer();

        void unpauseTimer();

        void checkTimer();

        void teleportToSpawn();
    };
}

#endif //GAMETEST_GHOST_H
