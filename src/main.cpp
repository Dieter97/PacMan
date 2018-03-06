#include <iostream>
#include "../include/Factory.h"
#include "../include/SDLFactory.h"
#include "../include/Game.h"

int main() {
    Factory* factory = new SDLFactory;
    auto * game = new Game();
    game->start(factory);
    delete(factory);
    return 0;
}