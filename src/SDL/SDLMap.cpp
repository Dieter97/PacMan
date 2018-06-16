//
// Created by dieter on 7/03/18.
//

#include "../../include/SDL/SDLMap.h"
using namespace SDL;

SDLMap::SDLMap(int width, int height, SDLContext *context) :
        Map(width, height) {
    this->context = context;
}

/**
 * SDL implementation of the map visualisation
 */
void SDLMap::visualize() {
    for(int i = 0; i < MAP_WIDTH; i++){
        for(int j = 0; j < MAP_HEIGHT; j++){
            tileMap[i][j]->visualize();
        }
    }
}

/**
 * Loads the map from a 2 dim array and load the sprites of given color
 * @param map
 * @param COLOR
 */
void SDLMap::loadMap(int** map, int COLOR) {
    //Fill tileMap with tiles from a reference map
    for(int i = 0; i < MAP_WIDTH; i++){
        for(int j = 0; j < MAP_HEIGHT; j++){
            tileMap[i][j] = new SDLTile(i, j, map[i][j], COLOR, context);
        }
    }
}

