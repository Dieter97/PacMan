//
// Created by dieter on 7/03/18.
//

#include <iostream>
#include "../include/Map.h"
#include "../include/Types.h"

Map::Map(int width, int height, int tileWidth, int tileHeigth) {
    MAP_HEIGHT = height;
    MAP_WIDTH = width;
    TILE_WIDTH = tileWidth;
    TILE_HEIGHT = tileHeigth;

    //Dynamically fill array with empty (abstract) tiles
    tileMap = new Tile **[MAP_WIDTH];
    for(int i=0;i<MAP_WIDTH;i++){
        tileMap[i] = new Tile*[MAP_HEIGHT];
    }
}

bool Map::checkCollision(Entity *e) {
    bool result = false;
    for(int i = 0; i<MAP_WIDTH;i++){
        for(int j = 0; j<MAP_HEIGHT;j++){
            int type = tileMap[i][j]->getTILETYPE();
            switch (type){
                case POINT_SMALL:
                    //POINT
                    result = tileMap[i][j]->collision(e);
                    if(result && e->getType() == PACMAN){
                        std::cout << "Point scored!" << std::endl;
                        tileMap[i][j]->setTILETYPE(BLANK);
                        return true;
                    }
                    break;
                case POINT_BIG:
                    //BIG point (energize)
                    result = tileMap[i][j]->collision(e);
                    if(result && e->getType() == PACMAN){
                        std::cout << "Bonus scored!" << std::endl;
                        tileMap[i][j]->setTILETYPE(BLANK);
                        return true;
                    }
                    break;
                case DOOR_HORIZONTAL:
                    result = tileMap[i][j]->collision(e);
                    if(result && e->getType() == PACMAN){
                        return true;
                    }
                case BLANK:
                    //DO nothing
                    break;
                default:
                    //Check regular collision with wall
                    result = tileMap[i][j]->collision(e);

                    if(result){
                        return result;
                    }
                    break;
            }
        }
    }
    return result;
}
