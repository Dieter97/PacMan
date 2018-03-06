//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include "Game.h"
#include "Types.h"

void Game::start(Factory* f) {

    //Init game
    bool quit = false;
    f->initDisplay();
    f->loadMedia();
    Event* events = f->createEventSystem();
    PacMan* player = f->createPacMan(10,0,2);
    Ghost* enemy1 = f->createGhost(20,20,1,RED_GHOST);
    Ghost* enemy2 = f->createGhost(180,250,1,BLUE_GHOST);
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
        player->visualize();
        enemy1-> move(DIR_UP);
        enemy1->visualize();
        enemy2-> move(DIR_LEFT);
        enemy2->visualize();
        enemy3-> move(DIR_RIGHT);
        enemy3->visualize();
        f->render();
    }

    //Close game
    f->close();
}

