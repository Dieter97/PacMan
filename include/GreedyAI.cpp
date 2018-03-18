//
// Created by dieter on 18/03/18.
//

#include "GreedyAI.h"
#include "Types.h"

GreedyAI::GreedyAI(Entity* target,Map* map): target(target) {
    int width = map->getMAP_WIDTH();
    int heigth = map->getMAP_HEIGHT();
    Tile*** tileMap = map->getTileMap();
    //Dynamically fill 2D array with all movable tiles
    this->map = new int *[width];
    for(int i=0;i<width;i++){
        this->map[i] = new int[heigth];
        for(int j =0;j<heigth;j++){
            int tile = tileMap[i][j]->getTILETYPE();
            if(tile == POINT_SMALL || tile == POINT_BIG || tile == BLANK){
                this->map[i][j] = 1;
            }else{
                this->map[i][j] = 0;
            }
        }
    }
}

int GreedyAI::nextDirection() {

    return rand() % 3;
}
