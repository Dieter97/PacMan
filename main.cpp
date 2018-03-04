#include <iostream>
#include "Factory.h"
#include "SDLFactory.h"
#include "DirectXFactory.h"
#include "Game.h"

int main() {
    Factory* factory = new SDLFactory;
    auto * game = new Game();
    game->start(factory);
    delete(factory);
    return 0;
}