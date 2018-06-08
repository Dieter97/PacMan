//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_INKY_H
#define GAMETEST_INKY_H

#include "AI.h"

class Inky : public AI {
private:
    int prev_dir = 0;
    int calculateShortest(float x1,float y1,float x2,float y2);
public:
    Inky(Map* m,int x,int y,MovingEntity*t);
    int getNextDirection(float posX, float posY, int mode) override ;

};


#endif //GAMETEST_INKY_H
