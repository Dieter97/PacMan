//
// Created by dieter on 26/02/18.
//

#include <zconf.h>
#include "Game.h"

void Game::start(Factory* f) {
    //TODO STARTUP GAME
    bool quit = false;
    f->initDisplay();


    Ghost* g = f->createGhost();
    g->visualize();
    f->clear();
    f->render();

    while(!quit){
        f->clear();
        switch (f->getEvent()){
            case f->KEY_PRESS_QUIT:
                quit = true;
                break;
            case f->KEY_PRESS_SURFACE_RIGHT:
                //TODO MOVE RIGHT
                g->move(1,0);
                break;
            case f->KEY_PRESS_SURFACE_LEFT:
                //TODO MOVE LEFT
                g->move(-1,0);
                break;
            case f->KEY_PRESS_SURFACE_UP:
                //TODO MOVE UP
                g->move(0,-1);
                break;
            case f->KEY_PRESS_SURFACE_DOWN:
                //TODO MOVE DOWN
                g->move(0,1);
                break;
            default:
                break;
        }
        g->visualize();
        f->render();
        usleep(1000);
    }


    f->close();
    //TODO Create main game loop

}

