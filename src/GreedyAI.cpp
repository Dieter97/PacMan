//
// Created by dieter on 18/03/18.
//

#include "../include/GreedyAI.h"
#include "../include/Types.h"

int GreedyAI::getNextDirection(float targetX, float targetY,int mode) {
    int direction = 0;
    switch (mode){
        case SCATTERING:
            //Random decision
            direction= rand() % 4;
            break;
        case CHASING:
            //Make 'intelligent' decision
            int dir[4][2] = {{0,1},{0,-1},
                             {1,0},{-1,0}};

            break;
        default:
            break;
    }

    return direction;
}