//
// Created by dieter on 7/03/18.
//

#include "../include/Map.h"

Map::Map(int width, int height, int tileWidth, int tileHeigth) {
    MAP_HEIGHT = height;
    MAP_WIDTH = width;
    TILE_WIDTH = tileWidth;
    TILE_HEIGHT = tileHeigth;

    tileMap = new Tile **[MAP_WIDTH];
    for(int i=0;i<MAP_WIDTH;i++){
        tileMap[i] = new Tile*[MAP_HEIGHT];
    }

}
