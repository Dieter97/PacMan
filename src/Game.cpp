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

void Game::start(Factory* f) {

    //Init game
    bool quit = false;
    f->initDisplay(995,500);
    f->loadMedia();


    PacMan* player;
    Ghost* enemy1;
    int *b[99];
    int map[99][99];
    int heigth = 0,width = 0;
    string line;
    ifstream level ("../resources/level.map");
    if (level.is_open())
    {

        level >> width; level >> heigth;
        int i = 0,j = 0,num = 0;
        while(level >> num || !level.eof()) {
            if(level.fail()) { // Number input failed, skip the word
                level.clear();
                string dummy;
                level >> dummy;
                continue;
            }
            switch (num){
                case PLAYER_SPAWN:
                    player = f->createPacMan((i*8*4)-4,(j*8*4)-4,3);
                    num = BLANK;
                    break;
                case RED_GHOST_SPAWN:
                    enemy1 = f->createGhost((i*8*4)-4,(j*8*4)-4,3,RED_GHOST);
                    num = BLANK;
                    break;
            }

            map[i][j] = num;
            j++;
            if(j>=heigth){
                i++;
                j = 0;
            }
            cout << num << endl;
        }
        for(int k = 0;k<width;k++){
            b[k] = map[k];
        }
        level.close();
    }

    else{
        cout << "Unable to open file";
        return;
    }



    Map* tiles = f->createMap(32,15);
    tiles->loadMap(b,BLUE_TILE);
    Event* events = f->createEventSystem();
    //PacMan* player = f->createPacMan(460,280,3);


    int playerDirection = DIR_LEFT;
    //Game loop
    while(!quit){
        f->clear();
        switch (events->getEvent()){
            case KEY_PRESS_QUIT:
                quit = true;
                break;
            case KEY_PRESS_SURFACE_RIGHT:
                playerDirection = DIR_RIGHT;
                break;
            case KEY_PRESS_SURFACE_LEFT:
                playerDirection = DIR_LEFT;
                break;
            case KEY_PRESS_SURFACE_UP:
                playerDirection = DIR_UP;
                break;
            case KEY_PRESS_SURFACE_DOWN:
                playerDirection = DIR_DOWN;
                break;
            default:
                break;
        }

        player->move(playerDirection);

        if(player->collision(enemy1)){
            std::cout << "Player colliding with ghost1!" << std::endl;
        }

        if(tiles->checkCollision(player)){
            //std::cout << "Player colliding with a Tile!" << std::endl;
            player->pushBack();
        }

        if(tiles->checkCollision(enemy1)){
            enemy1->pushBack();
        }

        tiles->visualize();

        enemy1-> move(playerDirection);
        enemy1->visualize();
        player->visualize();
        f->render();
    }

    //Close game
    f->close();
}

