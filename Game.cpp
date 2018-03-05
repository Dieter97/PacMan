//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include "Game.h"

void Game::start(Factory* f) {

    //Init game
    bool quit = false;
    f->initDisplay();
    Event* events = f->createEventSystem();
    Ghost* player = f->createGhost(0,0);
    Ghost* enemy1 = f->createGhost(20,20);
    Ghost* enemy2 = f->createGhost(180,250);
    enemy2->move(20,50);

    //Game loop
    while(!quit){
        f->clear();
        switch (events->getEvent()){
            case events->KEY_PRESS_QUIT:
                quit = true;
                break;
            case events->KEY_PRESS_SURFACE_RIGHT:
                player->move(2,0);
                break;
            case events->KEY_PRESS_SURFACE_LEFT:
                player->move(-2,0);
                break;
            case events->KEY_PRESS_SURFACE_UP:
                player->move(0,-2);
                break;
            case events->KEY_PRESS_SURFACE_DOWN:
                player->move(0,2);
                break;
            default:
                break;
        }
        player->visualize();
        enemy1-> move(0,1);
        enemy1->visualize();
        enemy2-> move(1,1);
        enemy2->visualize();
        f->render();
    }

    //Close game
    f->close();
}

