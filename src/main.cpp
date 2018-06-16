
#include "../include/logic/Factory.h"
#include "../include/SDL/SDLFactory.h"
#include "../include/logic/Game.h"

int main(int argc, char* argv[]) {
    //Create a new SDL factory to specify we want SDL visualisation
    logic::Factory* factory = new SDL::SDLFactory;
    auto * game = new logic::Game();
    std::string level = "../resources/original.map";
    std::cout << "Specify a level filename [default= original.map]: " << std::endl;
    char temp[100];
    std::cin.getline(temp,sizeof(temp));
    if(std::string(temp) != " " && std::string(temp) != ""){
        level = "../resources/"+std::string(temp);
    }
    if(game->initGame(factory,level)){
        game->start();
    }

    delete(factory);
    return 0;
}