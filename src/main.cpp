
#include "../include/Factory.h"
#include "../include/SDLFactory.h"
#include "../include/Game.h"

int main() {
    //Create a new SDL factory to specify we want SDL visualisation
    Factory* factory = new SDLFactory;
    auto * game = new Game();

    if(game->initGame(factory)){
        game->start();
    }

    delete(factory);
    return 0;
}