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
    int posY;
    static const int width=1;
    static const int heigth=1;
    int type;
public:
    int getType() const;

    void setType(int type);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    virtual void visualize() = 0;

    bool collision(const Entity* e);
};


#endif //GAMETEST_ENTITY_H
