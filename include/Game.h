//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_GAME_H
#define GAMETEST_GAME_H


#include "Factory.h"
#include "GameUI.h"
#include "Timer.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Clyde.h"
#include "Inky.h"


class Game {
public:
    void start();
    bool initGame(Factory* f);
    void handlePoint();
    void handleBonus();
    bool smoothRoundLocation(int dir,MovingEntity* e);
    void stop();
    void restart();
    void resetLevel();
private:
    int mapHeigth;
    int mapWidth;

    Factory* factory;

    //Entities
    PacMan* player;
    std::vector<Ghost*> enemies;
    Map* tileMap;
    Map* orgTileMap;
    Event* events;

    //Timers
    Timer* ghostTimer;
    Timer* fpsTimer;
    Timer* debounce;
    int countedFrames;

    //Game Variables
    int points;
    int neededPoints;
    int lives;
    int ghostMode;
    bool playing,paused,finished;

    //UI
    GameUI* ui;
};


#endif //GAMETEST_GAME_H
