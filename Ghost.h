//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


class Ghost {

protected:
    int x=0;
    int y=0;
    int windowX;
    int windowY;
    int velocity;
    int acc;
public:
    Ghost(int x, int y);
    void move(int deltaX,int deltaY);
    virtual void visualize()= 0;
};


#endif //GAMETEST_GHOST_H
