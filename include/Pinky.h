//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_PINKY_H
#define GAMETEST_PINKY_H

#include "AI.h"

class Pinky : public AI {
private:
    int prev_dir = 0;
    int calculateShortest(float x1,float y1,float x2,float y2);
public:
    Pinky(Map* m,int x,int y,MovingEntity*t);
    int getNextDirection(float posX, float posY, int mode) override ;

};


#endif //GAMETEST_PINKY_H
