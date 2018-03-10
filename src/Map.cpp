//
// Created by dieter on 7/03/18.
//

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
            if(type!=POINT_SMALL && type!=POINT_BIG && type != BLANK){
                result = tileMap[i][j]->collision(e);

                if(result){
                    return result;
                }
            }
        }
    }
    return result;
}
