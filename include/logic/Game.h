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
#include "../Types.h"
#include <string>
namespace logic {
    class Game {
    public:
        void start();

        bool initGame(Factory *f,std::string level);

        void handlePoint();

        void handleBonus();

        bool loadMap();

        void loadBrains();

        bool smoothRoundLocation(int dir, MovingEntity *e);

        void stop();

        void restart(Game *g);

        void resetLevel(Game *g);

    private:
        int mapHeigth;
        int mapWidth;
        std::string levelFile;
        Factory *factory;

        //Entities
        PacMan *player;
        std::vector<Ghost *> enemies;
        Map *tileMap;
        Event *events;

        //Timers
        Timer *ghostTimer;
        Timer *fpsTimer;
        Timer *debounce;
        int countedFrames;

        //Game Variables
        int points;
        int food;
        int neededPoints;
        int lives;
        int ghostMode;
        int level;
        bool playing, paused, finished;

        //UI
        GameUI *ui;
    };
}


#endif //GAMETEST_GAME_H
