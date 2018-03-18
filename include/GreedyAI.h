//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_GREEDYAI_H
#define GAMETEST_GREEDYAI_H


#include "Map.h"

class GreedyAI {
private:
    int** map;
    Entity* target;
public:
    GreedyAI(Entity* target,Map* map);
    int nextDirection();
};


#endif //GAMETEST_GREEDYAI_H
