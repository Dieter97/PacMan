//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include "Game.h"

void Game::start(Factory* f) {

    //Init game
    bool quit = false;
    f->initDisplay();
    Ghost* player = f->createGhost();
    Ghost* enemey1 = f->createGhost();

    //Game loop
    while(!quit){
        f->clear();
        switch (f->getEvent()){
            case f->KEY_PRESS_QUIT:
                quit = true;
                break;
            case f->KEY_PRESS_SURFACE_RIGHT:
                player->move(1,0);
                break;
            case f->KEY_PRESS_SURFACE_LEFT:
                player->move(-1,0);
                break;
            case f->KEY_PRESS_SURFACE_UP:
                player->move(0,-1);
                break;
            case f->KEY_PRESS_SURFACE_DOWN:
                player->move(0,1);
                break;
            default:
                break;
        }
        player->visualize();
        enemey1-> move(1,1);
        enemey1->visualize();
        f->render();
        usleep(10000);
    }

    //Close game
    f->close();
}

