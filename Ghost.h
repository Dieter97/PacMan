//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GHOST_H
#define GAMETEST_GHOST_H


class Ghost {

protected:
    int x;
    int y;
    int velocity;
    int acc;
public:
    Ghost();
    virtual void visualize()= 0;
};


#endif //GAMETEST_GHOST_H
