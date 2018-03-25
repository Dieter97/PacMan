//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include <iostream>
#include <fstream>
#include "../include/Game.h"
#include "../include/Types.h"
#include "../include/Map.h"
#include "../include/SDLMap.h"

using namespace std;


bool Game::initGame(Factory* f) {
    this->factory = f;
    ui = new GameUI();
    this->neededPoints = 0;
    //First load the map

    int *b[99];
    int map[99][99];
    string line;
    ifstream level ("../resources/level2.map");
    if (level.is_open())
    {
        //Read map parameters from level file
        level >> mapWidth; level >> mapHeigth;

        factory->initDisplay(mapWidth,mapHeigth+1);

        //Read the entire map from the file
        int i = 0,j = 0,num = 0;
        while(level >> num || !level.eof()) {
            if(level.fail()) { // Number input failed, skip the string
                level.clear();
                string dummy;
                level >> dummy;
                continue;
            }
            //Create entity based on input number
            switch (num){
                case PLAYER_SPAWN:
                    player = f->createPacMan(i, j,0.125f);
                    map[i][j] = BLANK;
                    break;
                case RED_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j,0.125f,RED_GHOST));
                    map[i][j] = BLANK;
                    break;
                case PINK_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j,0.125f,PINK_GHOST));
                    map[i][j] = BLANK;
                    break;
                case BLUE_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j,0.125f,BLUE_GHOST));
                    map[i][j] = BLANK;
                    break;
                case ORANGE_GHOST_SPAWN:
                    enemies.emplace_back(factory->createGhost(i, j,0.125f,ORANGE_GHOST));
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
            if(j>=mapHeigth){
                i++;
                j = 0;
            }
        }
        //convert 2D array to 1D array of pointers
        for(int k = 0;k<mapWidth;k++){
            b[k] = map[k];
        }
        level.close();
    }
    else{
        cout << "Error reading level file!";
        return false;
    }

    //Init game vars
    this->points = 0;
    this->lives = 3;

    //Init timers
    this->fpsTimer = factory->createTimer();
    this->ghostTimer = factory->createTimer();

    //Create UI elements
    ui->addTextView("start",factory->createTextView(mapWidth/2-6.5f,mapHeigth/2-3.2f,"Press space to start",18));
    ui->addTextView("score",factory->createTextView(0,mapHeigth,"Score: 0",12));
    ui->addTextView("lives",factory->createTextView(mapWidth-6,mapHeigth,"Lives: "+to_string(this->lives),12));

    //Create the level tile map
    tileMap = factory->createMap(mapWidth,mapHeigth);
    tileMap->loadMap(b,ORANGE_TILE);

    //Create event handler
    events = factory->createEventSystem();

    return true;
}

void Game::start() {

    //Init game loop vars
    bool quit = false;
    this->playing = false;
    int playerDirection = DIR_UP;
    int nextDirection = DIR_UP;

    //Start fpsTimer
    this->fpsTimer->start();
    this->countedFrames = 0;

    //Game loop
    while(!quit){

        //Calculate and correct fps
        float avgFPS = this->countedFrames / ( this->fpsTimer->getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
        cout << "\rFPS: " << avgFPS;

        //Clear screen
        factory->clear();

        //Player input
        switch (events->getEvent()){
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
                this->playing = true;
                break;
            default:
                break;
        }

        if(this->playing){
            ui->removeTextView("start");

            //First move the player
            //try the wanted dir
            player->move(nextDirection);

            //Check the player collision with map and other tiles
            int playerCollision = tileMap->checkCollision(player);
            switch(playerCollision){
                case NO_COLL:
                    playerDirection = nextDirection;
                    break;
                case COLL:
                    //player can't move in the desired dir move in old dir
                    player->pushBack();
                    player->move(playerDirection);
                    switch (tileMap->checkCollision(player)){
                        case COLL:
                            player->pushBack();
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
            for(auto const& enemy: enemies) {
                bool intersection = tileMap->isIntersection((int) roundf(enemy->getPosX()), (int) roundf(enemy->getPosY()));
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
                    enemy->getNextDirection();
                }
                if (player->collision(enemy)) {
                    //Player collision with enemy
                    //If pacman is energized kill ghost
                    switch (enemy->getSTATE()){
                        case FLEE:
                            enemy->setSTATE(DEAD);
                            break;
                        case DEAD:
                            //Do nothing
                            break;
                        default:
                            this->playing = false;
                            if(lives > 0){
                                //TODO ev set ghost back to spawn location
                                this->lives--;
                                ui->addTextView("start",factory->createTextView(mapWidth/2-6.5f,mapHeigth/2-3.2f,"Press space to start",18));
                                player->setPosX(player->getSpawnX());
                                player->setPosY(player->getSpawnY());
                                ui->changeText("lives","Lives: "+to_string(this->lives));
                            }else{
                                ui->addTextView("lose",factory->createTextView(mapWidth/2-2.5f,mapHeigth/2-3.8f,"Game over",18));
                            }
                            break;
                    }
                    cout << "Player colliding with a ghost!" << endl;
                }

                enemy->checkMapBounds(mapWidth - 1, mapHeigth - 1);
            }

            //Check ghost timer
            if(this->ghostTimer->isStarted()){
                if(this->ghostTimer->getTicks() > 8000){
                    this->ghostTimer->stop();
                    for(auto const& enemy: enemies){
                        if(enemy->getSTATE() != DEAD){enemy->setSTATE(enemy->getDIRECTION());}
                    }
                }
            }
        }

        //Render map
        tileMap->visualize();
        for(auto const& enemy: enemies){
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
    ui->changeText("score","Score: "+to_string(this->points));
    if(points >= neededPoints){
        ui->addTextView("win",factory->createTextView(mapWidth/2-2,mapHeigth/2,"YOU WIN!",18));
        this->playing = false;
    }
}

void Game::handleBonus() {
    //Set enemies in vulnerable state for 10 sec
    for(auto const& enemy: enemies){
        enemy->setSTATE(FLEE);
    }
    this->ghostTimer->start();
}

