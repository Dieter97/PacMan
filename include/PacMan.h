//
// Created by dieter on 6/03/18.
//

#ifndef GAMETEST_PACMAN_H
#define GAMETEST_PACMAN_H


#include "MovingEntity.h"

class PacMan : public MovingEntity {
public:
    PacMan(int posX, int posY,int width,int heigth, int speed);
};


#endif //GAMETEST_PACMAN_H
