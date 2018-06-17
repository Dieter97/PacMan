//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_ENTITY_H
#define GAMETEST_ENTITY_H

#include <math.h>

namespace logic {
    class Entity {
    protected:
        float width;
        float heigth;
        float posX;
        float posY;
        int type;

    public:
        Entity(float posX, float posY);

        Entity();

        int getType() const;

        void setType(int type);

        float getPosX() const;

        void setPosX(float posX);

        float getPosY() const;

        void setPosY(float posY);

        virtual void visualize() = 0;

        bool collision(const Entity *e);

        float getWidth() const;

        void setWidth(float width);

        float getHeigth() const;

        void setHeigth(float heigth);

    };
}


#endif //GAMETEST_ENTITY_H
