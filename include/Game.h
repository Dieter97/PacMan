//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H


#include "Factory.h"
#include "GameUI.h"
#include "Timer.h"
#include "Blinky.h"

class Game {
public:
    void start();
    bool initGame(Factory* f);
    void handlePoint();
    void handleBonus();
    bool smoothRoundLocation(int dir,MovingEntity* e);
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
    int neededPoints;
    int lives;
    bool playing;

    //UI
    GameUI* ui;
};


#endif //GAMETEST_GAME_H
