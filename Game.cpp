//
// Created by dieter on 26/02/18.
//

#include "Game.h"

void Game::start(Factory* f) {
    //TODO STARTUP GAME

    f->initDisplay();


    f->close();
    Ghost* g = f->createGhost();
    g->visualize();
    delete(g);

    //TODO Create main game loop

}

