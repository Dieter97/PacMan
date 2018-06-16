//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include <fstream>
#include "../include/Game.h"

/**
 *  Loads all game elements
 * @param f, Factory, this is the entity creator
 * @return bool, true if succes, false is fails
 */
bool Game::initGame(Factory *f) {
    this->factory = f;
    //Read the level
    this->levelFile = "../resources/level2.map";
    std::ifstream level(levelFile);
    if (level.is_open()) {
        //Read map parameters from level file
        level >> mapWidth;
        level >> mapHeigth;
        factory->initDisplay(mapWidth, mapHeigth + 1);
    } else {
        return false;
    }
    level.close();

    //Load the map
    if (!this->loadMap()) {
        return false;
    }

    //Init game vars
    this->points = 0;
    this->lives = 3;

    //Init timers
    this->fpsTimer = factory->createTimer();
    this->ghostTimer = factory->createTimer();
    this->debounce = factory->createTimer();

    //Create UI elements
    ui = new GameUI();
    ui->removeAllUI();
    ui->addTextView("start",
                    factory->createTextView(mapWidth / 2 - 6.5f, mapHeigth / 2 - 3.2f, "Press space to start", 18));
    ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: 0", 12));
    ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives: " + std::to_string(this->lives), 12));

    //Enable the AI for the enemies
    this->loadBrains();

    //Create event handler
    events = factory->createEventSystem();
    return true;
}

/**
 *  The main game loop contains the game logic
 */
void Game::start() {
    //Init game loop vars
    bool quit = false;
    this->playing = false;
    this->paused = false;
    this->finished = false;
    int playerDirection = DIR_UP;
    int nextDirection = DIR_UP;
    bool crossing = false;
    this->ghostMode = SCATTERING;
    this->ghostTimer->start();
    this->ghostTimer->pause();

    //Start fpsTimer
    this->fpsTimer->start();
    this->countedFrames = 0;

    //Game loop
    while (!quit) {

        //Calculate and correct fps
        float avgFPS = this->countedFrames / (this->fpsTimer->getTicks() / 1000.f);
        if (avgFPS > 2000000) {
            avgFPS = 0;
        }
        //cout << "FPS: " << avgFPS << endl;

        //Clear screen
        factory->clear();

        //Player input
        switch (events->getEvent()) {
            case KEY_PRESS_QUIT:
                quit = true;
                break;
            case KEY_PRESS_RIGHT:
                nextDirection = DIR_RIGHT;
                break;
            case KEY_PRESS_LEFT:
                nextDirection = DIR_LEFT;
                break;
            case KEY_PRESS_UP:
                nextDirection = DIR_UP;
                break;
            case KEY_PRESS_DOWN:
                nextDirection = DIR_DOWN;
                break;
            case KEY_PRESS_SPACE:
                if (!paused && !finished) {
                    this->playing = true;
                    this->ghostTimer->unpause();
                }
                break;
            case KEY_PRESS_ESC:
                if(!finished){
                    if (this->debounce->getTicks() > 200 || this->debounce->getTicks() == 0) {
                        this->debounce->stop();
                        if (this->playing) {
                            this->playing = false;
                            this->paused = true;
                            ui->addTextView("pause",
                                            factory->createTextView(mapWidth / 2 - 1.5f, mapHeigth / 3, "Paused", 18));
                            ui->addButton("restart_btn",
                                          factory->createButton(mapWidth / 2 - 2.2f, mapHeigth / 3 + 2.5f, "Restart game",
                                                                12, (Function) &Game::restart));
                            ui->addButton("exit_btn",
                                          factory->createButton(mapWidth / 2 - 1.5f, mapHeigth / 3 + 3.0f, "Exit game", 12,
                                                                (Function) &Game::stop));
                            this->ghostTimer->pause();
                            for (auto const &enemy: enemies) {
                                enemy->pauseTimer();
                            }
                            this->debounce->start();
                        } else {
                            this->playing = true;
                            this->paused = false;
                            ui->removeTextView("pause");
                            ui->removeButton("exit_btn");
                            ui->removeButton("restart_btn");
                            this->ghostTimer->unpause();
                            for (auto const &enemy: enemies) {
                                enemy->unpauseTimer();
                            }
                            this->debounce->start();
                        }
                    }
                }
            case MOUSE_CLICK:
                //Pass mouse click to ui
                ui->onClick(this);
            default:
                break;
        }


        //Game logic
        if (this->playing) {
            //Remove start text
            ui->removeTextView("start");

            //Unpause timers
            if(!paused && !finished){
                for (auto &enemy: enemies){
                    enemy->unpauseTimer();
                }
            }

            //First move the player
            //try the wanted dir
            player->move(nextDirection);

            //Check the player collision with map and other tiles
            int playerCollision = tileMap->checkCollision(player);
            //Clip location of player to rounded coordinates on tilemap
            if (playerDirection != nextDirection) {
                bool intersection = tileMap->isIntersection((int) roundf(player->getPosX()),
                                                            (int) roundf(player->getPosY()));
                // crossing = smoothRoundLocation(player->getDIRECTION(),player);
                if (!crossing && intersection) {
                    //
                    player->setPosX((int) roundf(player->getPosX()));
                    player->setPosY((int) roundf(player->getPosY()));
                    crossing = true;
                } else if (!intersection) {
                    crossing = false;
                }
            }
            //Check the players collision and react accordingly
            switch (playerCollision) {
                case NO_COLL:
                    playerDirection = nextDirection;
                    break;
                case COLL:
                    //player can't move in the desired dir move in old dir
                    player->pushBack();
                    player->move(playerDirection);
                    switch (tileMap->checkCollision(player)) {
                        case COLL:
                            player->pushBack();
                            player->setPosX((int) roundf(player->getPosX()));
                            player->setPosY((int) roundf(player->getPosY()));
                            break;
                        case POINT:
                            this->handlePoint();
                            break;
                        case BONUS:
                            this->handleBonus();
                            break;
                        default:
                            //Nothing
                            break;
                    }
                    break;
                case POINT:
                    this->handlePoint();
                    break;
                case BONUS:
                    this->handleBonus();
                    break;
                default:
                    //Nothing
                    break;
            }
            //Player stay inside play area
            player->checkMapBounds(mapWidth - 1, mapHeigth - 1);

            //Collision and movement for enemies
            for (auto &enemy: enemies) {
                //Check the enemies timer for leaving the ghost house
                enemy->checkTimer();
                //Check if ghost has arrived at ghosthouse
                if ((round(enemy->getPosX()) == enemy->getTargetX() && round(enemy->getPosY()) == enemy->getTargetY()) &&
                        enemy->getMODE() == DEAD) {
                    enemy->setMODE(HOME);
                    enemy->startTimer(2000); //Stay in ghost house for 2 seconds
                }
                //check if the ghost succesfully left the ghost house
                if ((round(enemy->getPosX()) == enemy->getTargetX() && round(enemy->getPosY()) == enemy->getTargetY()) &&
                    enemy->getMODE() == LEAVE) {
                    enemy->setMODE(SCATTERING);
                }
                //Check if ghost on intersection tile if so choose a new direction and move the whole tile
                //the ghost is only able to choose a one new direction per intersection tile and cannot go back
                bool intersection = tileMap->isIntersection((int) roundf(enemy->getPosX()),
                                                            (int) roundf(enemy->getPosY()));
                if (!enemy->isChangedDir() && intersection) {
                    //Keep moving out of the intersection tile
                    enemy->setChangedDir(1);
                    int currentDir = enemy->getDIRECTION();
                    enemy->setPosX((int) roundf(enemy->getPosX()));
                    enemy->setPosY((int) roundf(enemy->getPosY()));
                    enemy->getNextDirection();
                    enemy->move();

                } else if (intersection) {
                    int currX = (int) enemy->getPosX();
                    int currY = (int) enemy->getPosY();
                    enemy->move();
                    int newX = (int) enemy->getPosX();
                    int newY = (int) enemy->getPosY();
                    //Check if crossing into a next tile
                    if(currX != newX || currY != newY){
                        enemy->setChangedDir(0);
                    }
                } else {
                    enemy->move();
                    enemy->setChangedDir(0);
                }

                //Check collision for the enemy and react accordingly
                if (tileMap->checkCollision(enemy)) {
                    enemy->pushBack();
                    enemy->setPosX((int) roundf(enemy->getPosX()));
                    enemy->setPosY((int) roundf(enemy->getPosY()));
                    enemy->getNextDirection();
                }

                //Check collision for enemy with player and react accordingly
                if (player->collision(enemy)) {
                    //Player collision with enemy
                    //If pacman is energized kill ghost
                    switch (enemy->getMODE()) {
                        case FLEE:
                            enemy->setMODE(DEAD);
                            this->points = this->points + 10;
                            this->ui->changeTextView("score", "Score: " + std::to_string(this->points));
                            break;
                        case DEAD:
                            //Do nothing
                            break;
                        default:
                            this->playing = false;
                            if (lives > 0) {
                                //Teleport Enemies to spawn
                                this->loadBrains();
                                for (auto &enemie: enemies){
                                    enemie->teleportToSpawn();
                                    enemie->startTimer(100);
                                }
                                this->lives--;
                                ui->addTextView("start",
                                                factory->createTextView(mapWidth / 2 - 6.5f, mapHeigth / 2 - 3.2f,
                                                                        "Press space to start", 18));
                                player->setPosX(player->getSpawnX());
                                player->setPosY(player->getSpawnY());
                                ui->changeTextView("lives", "Lives: " + std::to_string(this->lives));
                            } else {
                                this->finished = true;
                                ui->addTextView("lose",
                                                factory->createTextView(mapWidth / 2 - 2.5f, mapHeigth / 2 - 3.8f,
                                                                        "Game over", 18));
                                ui->addButton("restart_btn",
                                              factory->createButton(mapWidth / 2 - 2.2f, mapHeigth / 2 + 1.5f,
                                                                    "Restart game", 12, (Function) &Game::restart));
                                ui->addButton("exit_btn",
                                              factory->createButton(mapWidth / 2 - 1.5f, mapHeigth / 2 + 2.5f,
                                                                    "Exit game", 12, (Function) &Game::stop));
                            }
                            break;
                    }
                    std::cout << "Player colliding with a ghost!" << std::endl;
                }
                //Ghost stay inside play area
                enemy->checkMapBounds(mapWidth - 1, mapHeigth - 1);
            }

            //Check ghost timer
            if (this->ghostTimer->isStarted()) {
                switch (this->ghostMode) {
                    case SCATTERING:
                        if (this->ghostTimer->getTicks() > 5000) {
                            this->ghostMode = CHASING;
                            std::cout << "Starting to chase" << std::endl;
                            this->ghostTimer->stop();
                            for (auto const &enemy: enemies) {
                                if (enemy->getMODE() != DEAD   && enemy->getMODE() != HOME && enemy->getMODE() != LEAVE  ) {
                                    enemy->setSTATE(enemy->getDIRECTION());
                                    enemy->setMODE(CHASING);
                                }
                            }
                            this->ghostTimer->start();
                        }
                        break;
                    case CHASING:
                        if (this->ghostTimer->getTicks() > 20000) {
                            std::cout << "Starting to scatter" << std::endl;
                            this->ghostMode = SCATTERING;
                            this->ghostTimer->stop();
                            for (auto const &enemy: enemies) {
                                if (enemy->getMODE() != DEAD  && enemy->getMODE() != HOME && enemy->getMODE() != LEAVE ) {
                                    enemy->setSTATE(enemy->getDIRECTION());
                                    enemy->setMODE(SCATTERING);
                                }
                            }
                            this->ghostTimer->start();
                        }
                        break;
                    case FLEE:
                        if (this->ghostTimer->getTicks() > 5000) {
                            this->ghostMode = SCATTERING;
                            this->ghostTimer->stop();
                            for (auto const &enemy: enemies) {
                                if (enemy->getMODE() != DEAD) {
                                    enemy->setSTATE(enemy->getDIRECTION());
                                    enemy->setMODE(SCATTERING);
                                }
                            }
                            this->ghostTimer->start();
                        }
                        break;
                }
            }
        }

        //Render map --order: 1.map 2.enemies 3.player 4.ui
        tileMap->visualize();
        for (auto const &enemy: enemies) {
            enemy->visualize();
        }
        player->visualize();
        ui->visualize();
        factory->render();
        this->countedFrames++;
    }

    //Close game
    factory->close();
}

/**
 *  Increments the points and checks if the players wins the current level
 */
void Game::handlePoint() {
    this->points++;
    this->food++;
    this->ui->changeTextView("score", "Score: " + std::to_string(this->points));
    if ((food % neededPoints) == 0) {
        this->finished = true;
        ui->addTextView("win", factory->createTextView(mapWidth / 2 - 2, mapHeigth / 2, "YOU WIN!", 18));
        ui->addButton("next_btn", factory->createButton(mapWidth / 2 - 1.5f, mapHeigth / 2 + 3.0f, "Next level", 12,
                                                        (Function) &Game::resetLevel));
        this->playing = false;
    }
}

/**
 *  Handles a bonus pickup: energize the player
 */
void Game::handleBonus() {
    //Set enemies in vulnerable state for XX seconds
    this->points = this->points + 5;
    this->ui->changeTextView("score", "Score: " + std::to_string(this->points));
    this->ghostTimer->stop();
    this->ghostMode = FLEE;
    for (auto const &enemy: enemies) {
        if(enemy->getMODE() != DEAD && enemy->getMODE() != HOME) {
            enemy->setMODE(FLEE);
        }
    }
    this->ghostTimer->start();
}

/**
 *  Loads the AI and initiates it in the correct mode
 */
void Game::loadBrains() {
    //Initiate brains(AI) for enemies
    for (auto const &enemy: enemies) {
        switch (enemy->getName()) {
            case BLINKY:
                enemy->setBrain(new Blinky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                enemy->setMODE(SCATTERING);
                break;
            case PINKY:
                enemy->setBrain(new Pinky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                enemy->setMODE(HOME);
                enemy->startTimer(2000); //Leave ghost house after 2s
                enemy->pauseTimer();
                break;
            case INKY:
                enemy->setBrain(new Inky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                enemy->setMODE(HOME);
                enemy->startTimer(5000); //Leave ghost house after 5s
                enemy->pauseTimer();
                break;
            case CLYDE:
                enemy->setBrain(new Clyde(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                enemy->setMODE(HOME);
                enemy->startTimer(7000); //Leave ghost house after 7s
                enemy->pauseTimer();
                break;
            default:
                //nothing
                break;
        }
    }
}

/**
 * Loads the level and creates all entities
 * @return bool, true is success, false if fails
 */
bool Game::loadMap() {
    int *b[99];
    int map[99][99];
    int levelColor;
    this->neededPoints = 0;
    std::string line;
    std::ifstream level(levelFile);
    if (level.is_open()) {
        int n, m;
        //skip the first line
        level >> n;
        level >> m;
        level >> levelColor;
        //Read the entire map from the file
        int i = 0, j = 0, num = 0;
        while (level >> num || !level.eof()) {
            if (level.fail()) { // Number input failed, skip the string
                level.clear();
                std::string dummy;
                level >> dummy;
                continue;
            }
            //Create entity based on input number
            switch (num) {
                case PLAYER_SPAWN:
                    player = factory->createPacMan(i, j, 0.125f);
                    map[i][j] = BLANK;
                    break;
                case RED_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j, 0.1f, RED_GHOST));
                    map[i][j] = BLANK;
                    break;
                case PINK_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j, 0.1f, PINK_GHOST));
                    map[i][j] = BLANK;
                    break;
                case BLUE_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j, 0.1f, BLUE_GHOST));
                    map[i][j] = BLANK;
                    break;
                case ORANGE_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j, 0.1f, ORANGE_GHOST));
                    map[i][j] = BLANK;
                    break;
                case POINT_SMALL:
                    this->neededPoints++;
                    map[i][j] = num;
                    break;
                default:
                    map[i][j] = num;
                    break;
            }
            j++;
            if (j >= mapHeigth) {
                i++;
                j = 0;
            }
        }
        //convert 2D array to 1D array of pointers
        for (int k = 0; k < mapWidth; k++) {
            b[k] = map[k];
        }
    } else {
        std::cout << "Error reading level file!";
        return false;
    }
    level.close();

    //Create the level tile map
    tileMap = factory->createMap(mapWidth, mapHeigth);
    tileMap->loadMap(b, levelColor);
    return true;
}

/**
 *  Quits the game
 */
void Game::stop() {
    std::cout << "BYE";
    exit(0);
}

/**
 *  Resets all the game elements
 * @param g, Game object, reference to this game object to reload the elements
 */
void Game::restart(Game *g) {
    std::cout << "Restarting game!" << std::endl;
    g->finished = false;
    g->paused = false;
    g->playing = false;
    g->points = 0;
    g->food = 0;
    g->lives = 3;
    g->enemies.clear();
    g->loadMap();
    g->loadBrains();
    g->ghostTimer->stop();
    g->ghostTimer->start();
    g->ghostTimer->pause();
    //Create UI elements
    g->ui->removeAllUI();
    g->ui->addTextView("start", g->factory->createTextView(g->mapWidth / 2 - 6.5f, g->mapHeigth / 2 - 3.2f,
                                                           "Press space to start", 18));
    g->ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: 0", 12));
    g->ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives:3", 12));
}

/**
 *  Resets only the level and the ghosts
 * @param g, Game object, reference to this game object to reload the elements
 */
void Game::resetLevel(Game *g) {
    std::cout << "Restarting game!" << std::endl;
    g->finished = false;
    g->paused = false;
    g->playing = false;
    g->enemies.clear();
    g->food = 0;
    g->loadMap();
    g->loadBrains();
    g->lives++;
    g->ui->removeAllUI();
    g->ui->addTextView("start", g->factory->createTextView(g->mapWidth / 2 - 6.5f, g->mapHeigth / 2 - 3.2f,
                                                           "Press space to start", 18));
    g->ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: " + std::to_string(g->points), 12));
    g->ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives: " + std::to_string(g->lives), 12));
}

/**
 * Rounds and sets an entity's locations
 * @param dir, the entity's (wanted) direction
 * @param e, the entity
 * @return bool
 */
bool Game::smoothRoundLocation(int dir, MovingEntity *e) {
    bool result = false;
    switch (dir) {
        case DIR_UP:
            if ((roundf(e->getPosY()) + e->getSpeed()) < e->getPosY()) {
                e->setPosX((int) roundf(e->getPosX()));
                e->setPosY((int) roundf(e->getPosY()));
                result = true;
            }
            break;
        case DIR_DOWN:
            if ((roundf(e->getPosY()) - e->getSpeed()) > e->getPosY()) {
                e->setPosX((int) roundf(e->getPosX()));
                e->setPosY((int) roundf(e->getPosY()));
                result = true;
            }
            break;
        case DIR_LEFT:
            if ((roundf(e->getPosX()) - e->getSpeed()) < e->getPosX()) {
                e->setPosX((int) roundf(e->getPosX()));
                e->setPosY((int) roundf(e->getPosY()));
                result = true;
            }
            break;
        case DIR_RIGHT:
            if ((roundf(e->getPosX()) + e->getSpeed()) > e->getPosX()) {
                e->setPosX((int) roundf(e->getPosX()));
                e->setPosY((int) roundf(e->getPosY()));
                result = true;
            }
            break;
        default:
            result = false;
            break;
    }
    return result;
}


