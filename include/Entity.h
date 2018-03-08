//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H


class Entity {
protected:
public:
    Entity(int posX, int posY);

    Entity();

protected:
    int posX;
public:
    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

protected:
    int posY;
public:
    virtual void visualize() = 0;
};


#endif //GAMETEST_ENTITY_H
