//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H


#include "Factory.h"
#include "../src/UI/GameUI.h"

class Game {
public:
    void start();
    bool initGame(Factory* f);

private:
    int mapHeigth;
    int mapWidth;

    Factory* factory;

    //Entities
    PacMan* player;
    std::vector<Ghost*> enemies;
    Map* tileMap;
    Event* events;

    //Game Variables
    int points;

    //UI
    GameUI* ui;
};


#endif //GAMETEST_GAME_H
