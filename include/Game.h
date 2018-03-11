//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H


#include "Factory.h"

class Game {
public:
    void start();
    bool initGame(Factory* f);

private:
    int windowHeigth;
    int windowWidth;
    int mapHeigth;
    int mapWidth;

    Factory* factory;

    //Entities
    PacMan* player;
    std::vector<Ghost*> enemies;
    Map* tileMap;
    Event* events;
};


#endif //GAMETEST_GAME_H
