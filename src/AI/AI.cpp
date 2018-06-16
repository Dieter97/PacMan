//
// Created by dieter on 18/03/18.
//

#include "../../include/logic/AI.h"
using namespace logic;

AI::AI(Map *m,int x,int y,MovingEntity* t) : map(m),spawnX(x),spawnY(y),target(t){
    AI::doorX = (int) map->getDoorX();
    AI::doorY = (int) map->getDoorY();
}

float AI::getTargetX() {
    return doorX;
}

float AI::getTargetY() {
    return doorY;
}
