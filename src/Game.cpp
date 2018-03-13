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

    //First load the map

    int *b[99];
    int map[99][99];
    string line;
    ifstream level ("../resources/level2.map");
    if (level.is_open())
    {
        //Read map parameters from level file
        level >> mapWidth; level >> mapHeigth;

        factory->initDisplay(mapWidth,mapHeigth);

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

    //Create the level tile map
    tileMap = factory->createMap(mapWidth,mapHeigth);
    tileMap->loadMap(b,BLUE_TILE);

    //Create event handler
    events = factory->createEventSystem();
    return true;
}

void Game::start() {

    //Init game
    bool quit = false;


    int playerDirection = DIR_LEFT;
    int nextDirection = DIR_LEFT;
    //Game loop
    while(!quit){
        factory->clear();
        switch (events->getEvent()){
            case KEY_PRESS_QUIT:
                quit = true;
                break;
            case KEY_PRESS_SURFACE_RIGHT:
                nextDirection = DIR_RIGHT;
                break;
            case KEY_PRESS_SURFACE_LEFT:
                nextDirection = DIR_LEFT;
                break;
            case KEY_PRESS_SURFACE_UP:
                nextDirection = DIR_UP;
                break;
            case KEY_PRESS_SURFACE_DOWN:
                nextDirection = DIR_DOWN;
                break;
            default:
                break;
        }


        player->move(nextDirection);

        //Render map
        tileMap->visualize();

        //Map collision for player
        if(tileMap->checkCollision(player)){
            //std::cout << "Player colliding with a Tile!" << std::endl;
            player->pushBack();
            player->move(playerDirection);
            if(tileMap->checkCollision(player)){
                player->pushBack();
            }
        }else{
            playerDirection = nextDirection;
        }

        player->checkMapBounds(mapWidth,mapHeigth);

        //Collision for enemies
        for(auto const& enemy: enemies){
            if(tileMap->checkCollision(enemy)){
                enemy->pushBack();
            }
            if(player->collision(enemy)){
                //Player collision with enemy
                //TODO HANDLE ENEMY COLLISION
                cout << "Player colliding with a ghost!" << endl;
            }
            enemy-> move(nextDirection);
            enemy->checkMapBounds(mapWidth,mapHeigth);
            enemy->visualize();
        }

        player->visualize();
        factory->render();
    }

    //Close game
    factory->close();
}

