//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H


class Entity {
protected:
public:
    Entity(int posX, int posY,int width,int height);

    Entity();

protected:
    int posX;
    int posY;
    int width;
    int heigth;
public:
    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    virtual void visualize() = 0;

    virtual bool collision(Entity* e) = 0;
};


#endif //GAMETEST_ENTITY_H
