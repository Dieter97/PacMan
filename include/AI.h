//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_AI_H
#define GAMETEST_AI_H


#include "Map.h"

class AI {

public:
    virtual int getNextDirection(float targetX, float targetY, int mode) = 0;
};


#endif //GAMETEST_AI_H
