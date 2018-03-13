//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H


class Entity {
protected:
public:
    Entity(float posX, float posY);

    Entity();

protected:
    float posX;
    float posY;
    static const int width = 1;
    static const int heigth = 1;
    int type;
public:
    int getType() const;

    void setType(int type);

    float getPosX() const;

    void setPosX(float posX);

    float getPosY() const;

    void setPosY(float posY);

    virtual void visualize() = 0;

    bool collision(const Entity* e);

};


#endif //GAMETEST_ENTITY_H
