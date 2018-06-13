//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include <fstream>
#include "../include/Game.h"

using namespace std;


bool Game::initGame(Factory *f) {
    this->factory = f;
    ui = new GameUI();
    this->levelFile = "../resources/level2.map";
    ifstream level(levelFile);
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
    ui->removeAllUI();
    ui->addTextView("start",
                    factory->createTextView(mapWidth / 2 - 6.5f, mapHeigth / 2 - 3.2f, "Press space to start", 18));
    ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: 0", 12));
    ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives: " + to_string(this->lives), 12));

    this->loadBrains();

    //Create event handler
    events = factory->createEventSystem();

    return true;
}

void Game::loadBrains() {
    //Initiate brains(AI) for enemies
    for (auto const &enemy: enemies) {
        switch (enemy->getName()) {
            case BLINKY:
                enemy->setBrain(new Blinky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                break;
            case PINKY:
                enemy->setBrain(new Pinky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                break;
            case INKY:
                enemy->setBrain(new Inky(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                break;
            case CLYDE:
                enemy->setBrain(new Clyde(this->tileMap, (int) enemy->getSpawnX(), (int) enemy->getSpawnY(), player));
                break;
            default:
                //nothing
                break;
        }
    }
}

bool Game::loadMap() {
    int *b[99];
    int map[99][99];
    this->neededPoints = 0;
    string line;
    ifstream level(levelFile);
    if (level.is_open()) {
        int n, m;
        //skip the first line
        level >> n;
        level >> m;
        //Read the entire map from the file
        int i = 0, j = 0, num = 0;
        while (level >> num || !level.eof()) {
            if (level.fail()) { // Number input failed, skip the string
                level.clear();
                string dummy;
                level >> dummy;
                continue;
            }
            //Create entity based on input number
            switch (num) {
                case PLAYER_SPAWN:
                    player = factory->createPacMan(i, j, 0.250f);
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
        cout << "Error reading level file!";
        return false;
    }
    level.close();

    //Create the level tile map
    tileMap = factory->createMap(mapWidth, mapHeigth);
    tileMap->loadMap(b, BLUE_TILE);
    return true;
}

void Game::stop() {
    std::cout << "BYE";
    exit(0);
}

void Game::restart(Game *g) {
    std::cout << "Restarting game!" << std::endl;
    g->finished = false;
    g->paused = false;
    g->playing = false;
    g->points = 0;
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
    ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: 0", 12));
    ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives:3", 12));
}

void Game::resetLevel(Game *g) {
    std::cout << "Restarting game!" << std::endl;
    g->finished = false;
    g->paused = false;
    g->playing = false;
    g->enemies.clear();
    g->loadMap();
    g->loadBrains();
    g->lives++;
    g->ui->removeAllUI();
    g->ui->addTextView("start", g->factory->createTextView(g->mapWidth / 2 - 6.5f, g->mapHeigth / 2 - 3.2f,
                                                           "Press space to start", 18));
    ui->addTextView("score", factory->createTextView(0, mapHeigth, "Score: " + to_string(g->points), 12));
    ui->addTextView("lives", factory->createTextView(mapWidth - 6, mapHeigth, "Lives: " + to_string(g->lives), 12));
}

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
                        this->debounce->start();
                    } else {
                        this->playing = true;
                        this->paused = false;
                        ui->removeTextView("pause");
                        ui->removeButton("exit_btn");
                        ui->removeButton("restart_btn");
                        this->ghostTimer->unpause();
                        this->debounce->start();
                    }
                } else {
                    this->ghostTimer->unpause();
                }
            case MOUSE_CLICK:
                ui->onClick(this);
            default:
                break;
        }

        if (this->playing) {
            ui->removeTextView("start");

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
            player->checkMapBounds(mapWidth - 1, mapHeigth - 1);

            //Collision and movement for enemies
            for (auto const &enemy: enemies) {
                if ((round(enemy->getPosX()) == enemy->getTargetX() && round(enemy->getPosY()) == enemy->getTargetY()) &&
                        enemy->getMODE() == DEAD) {
                    enemy->setMODE(SCATTERING);
                }
                bool intersection = tileMap->isIntersection((int) roundf(enemy->getPosX()),
                                                            (int) roundf(enemy->getPosY()));
                if (!enemy->isChangedDir() && intersection) {
                    enemy->setChangedDir(1);
                    enemy->setPosX((int) roundf(enemy->getPosX()));
                    enemy->setPosY((int) roundf(enemy->getPosY()));
                    enemy->move(enemy->getNextDirection());
                } else if (intersection) {
                    enemy->move();
                } else {
                    enemy->move();
                    enemy->setChangedDir(0);
                }
                if (tileMap->checkCollision(enemy)) {
                    enemy->pushBack();
                    enemy->setPosX((int) roundf(enemy->getPosX()));
                    enemy->setPosY((int) roundf(enemy->getPosY()));
                    enemy->getNextDirection();
                }
                if (player->collision(enemy)) {
                    //Player collision with enemy
                    //If pacman is energized kill ghost
                    switch (enemy->getMODE()) {
                        case FLEE:
                            enemy->setMODE(DEAD);
                            this->points = this->points + 10;
                            this->ui->changeTextView("score", "Score: " + to_string(this->points));
                            break;
                        case DEAD:
                            //Do nothing
                            break;
                        default:
                            this->playing = false;
                            if (lives > 0) {
                                //TODO ev set ghost back to spawn location + set points function
                                this->lives--;
                                ui->addTextView("start",
                                                factory->createTextView(mapWidth / 2 - 6.5f, mapHeigth / 2 - 3.2f,
                                                                        "Press space to start", 18));
                                player->setPosX(player->getSpawnX());
                                player->setPosY(player->getSpawnY());
                                ui->changeTextView("lives", "Lives: " + to_string(this->lives));
                            } else {
                                this->finished = true;
                                ui->addTextView("lose",
                                                factory->createTextView(mapWidth / 2 - 2.5f, mapHeigth / 2 - 3.8f,
                                                                        "Game over", 18));
                                ui->addButton("restart_btn",
                                              factory->createButton(mapWidth / 2 - 2.2f, mapHeigth / 3 + 1.5f,
                                                                    "Restart game", 12, (Function) &Game::restart));
                                ui->addButton("exit_btn",
                                              factory->createButton(mapWidth / 2 - 1.5f, mapHeigth / 3 + 2.0f,
                                                                    "Exit game", 12, (Function) &Game::stop));
                            }
                            break;
                    }
                    cout << "Player colliding with a ghost!" << endl;
                }

                enemy->checkMapBounds(mapWidth - 1, mapHeigth - 1);
            }

            //Check ghost timer
            if (this->ghostTimer->isStarted()) {
                switch (this->ghostMode) {
                    case SCATTERING:
                        if (this->ghostTimer->getTicks() > 7000) {
                            this->ghostMode = CHASING;
                            cout << "Starting to chase" << endl;
                            this->ghostTimer->stop();
                            for (auto const &enemy: enemies) {
                                if (enemy->getMODE() != DEAD) {
                                    enemy->setSTATE(enemy->getDIRECTION());
                                    enemy->setMODE(CHASING);
                                }
                            }
                            this->ghostTimer->start();
                        }
                        break;
                    case CHASING:
                        if (this->ghostTimer->getTicks() > 20000) {
                            cout << "Starting to scatter" << endl;
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

        //Render map
        tileMap->visualize();
        for (auto const &enemy: enemies) {
            enemy->visualize();
        }
        ui->visualize();
        player->visualize();
        factory->render();

        this->countedFrames++;
    }

    //Close game
    factory->close();
}

void Game::handlePoint() {
    this->points++;
    this->food++;
    this->ui->changeTextView("score", "Score: " + to_string(this->points));
    if ((food % neededPoints) == 0) {
        ui->addTextView("win", factory->createTextView(mapWidth / 2 - 2, mapHeigth / 2, "YOU WIN!", 18));
        ui->addButton("next_btn", factory->createButton(mapWidth / 2 - 1.5f, mapHeigth / 2 + 3.0f, "Next level", 12,
                                                        (Function) &Game::resetLevel));
        this->playing = false;
    }
}

void Game::handleBonus() {
    //Set enemies in vulnerable state for XX seconds
    this->points = this->points + 5;
    this->ui->changeTextView("score", "Score: " + to_string(this->points));
    this->ghostTimer->stop();
    for (auto const &enemy: enemies) {
        if(enemy->getMODE() != DEAD) {
            enemy->setMODE(FLEE);
        }
    }
    this->ghostTimer->start();
}

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


