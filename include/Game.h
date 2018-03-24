//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H


#include "Factory.h"
#include "GameUI.h"
#include "../src/Timing/Timer.h"

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

    //Timers
    Timer* ghostTimer;
    Timer* fpsTimer;
    int countedFrames;

    //Game Variables
    int points;
    int lives;

    //UI
    GameUI* ui;
};


#endif //GAMETEST_GAME_H
