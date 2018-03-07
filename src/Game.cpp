//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include "../include/Game.h"
#include "../include/Types.h"

void Game::start(Factory* f) {

    //Init game
    bool quit = false;
    f->initDisplay();
    f->loadMedia();
    Tile* tile1 = f->createTile(40,60,POINT_BIG,PINK_TILE);
    Event* events = f->createEventSystem();
    PacMan* player = f->createPacMan(10,0,3);
    Ghost* enemy1 = f->createGhost(20,20,2,RED_GHOST);
    Ghost* enemy2 = f->createGhost(180,250,2,BLUE_GHOST);
    Ghost* enemy3 = f->createGhost(170,140,1,PINK_GHOST);

    //Game loop
    while(!quit){
        f->clear();
        switch (events->getEvent()){
            case KEY_PRESS_QUIT:
                quit = true;
                break;
            case KEY_PRESS_SURFACE_RIGHT:
                player->move(DIR_RIGHT);
                break;
            case KEY_PRESS_SURFACE_LEFT:
                player->move(DIR_LEFT);
                break;
            case KEY_PRESS_SURFACE_UP:
                player->move(DIR_UP);
                break;
            case KEY_PRESS_SURFACE_DOWN:
                player->move(DIR_DOWN);
                break;
            default:
                break;
        }
        tile1->visualize();
        tile2->visualize();
        tile3->visualize();
        enemy1-> move(DIR_UP);
        enemy1->visualize();
        enemy2-> move(DIR_LEFT);
        enemy2->visualize();
        enemy3-> move(DIR_RIGHT);
        enemy3->visualize();
        player->visualize();
        f->render();
    }

    //Close game
    f->close();
}

