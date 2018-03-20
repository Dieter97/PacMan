//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_MOVINGENTITY_H
#define GAMETEST_MOVINGENTITY_H


#include "Entity.h"

class MovingEntity : public Entity {
protected:
    int STATE;
    float speed;
    bool changedDir = false;
public:
    bool isChangedDir() const;

    void setChangedDir(bool changedDir);

    MovingEntity(float posX, float posY, float speed);

    void move(int direction);

    void pushBack();

    void checkMapBounds(int mapWidth,int mapHeigth) ;

    void move();
};


#endif //GAMETEST_MOVINGENTITY_H
