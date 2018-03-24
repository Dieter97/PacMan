//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_MOVINGENTITY_H
#define GAMETEST_MOVINGENTITY_H


#include "Entity.h"

class MovingEntity : public Entity {
protected:
    int DIRECTION;
    float speed;
    bool changedDir = false;
    float spawnX;
    float spawnY;
public:
    bool isChangedDir() const;
    void setChangedDir(bool changedDir);
    MovingEntity(float posX, float posY, float speed);
    void move(int direction);
    void pushBack();
    void checkMapBounds(int mapWidth,int mapHeigth) ;
    void move();
    int getDIRECTION() const;

    float getSpawnX() const;

    float getSpawnY() const;
};


#endif //GAMETEST_MOVINGENTITY_H
