//
// Created by dieter on 6/03/18.
//

#ifndef GAMETEST_PACMAN_H
#define GAMETEST_PACMAN_H


#include "MovingEntity.h"

namespace logic {
    class PacMan : public MovingEntity {
    protected:
        int STATE;
    public:
        PacMan(float posX, float posY, float speed);

        int getSTATE() const;

        void setSTATE(int STATE);
    };
}


#endif //GAMETEST_PACMAN_H
