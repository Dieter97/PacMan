//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H


class Entity {
protected:
public:
    Entity(int posX, int posY);

protected:
    int posX;
    int posY;
public:
    virtual void visualize() = 0;
};


#endif //GAMETEST_ENTITY_H
