//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_GREEDYAI_H
#define GAMETEST_GREEDYAI_H

#include "AI.h"

class GreedyAI : public AI {
public:
    int getNextDirection(float targetX, float targetY, int mode) override ;
};


#endif //GAMETEST_GREEDYAI_H
