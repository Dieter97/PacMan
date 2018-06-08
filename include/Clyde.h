//
// Created by dieter on 18/03/18.
//

#ifndef GAMETEST_CLYDE_H
#define GAMETEST_CLYDE_H

#include "AI.h"

class Clyde : public AI {
private:
    int prev_dir = 0;
    int calculateShortest(float x1,float y1,float x2,float y2);
public:
    Clyde(Map* m,int x,int y,MovingEntity*t);
    int getNextDirection(float posX, float posY, int mode) override ;

};


#endif //GAMETEST_CLYDE_H
