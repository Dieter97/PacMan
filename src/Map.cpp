//
// Created by dieter on 7/03/18.
//

#include "../include/logic/Map.h"
#include "../include/Types.h"
using namespace logic;

Map::Map(int width, int height) {
    MAP_HEIGHT = height;
    MAP_WIDTH = width;

    //Dynamically fill array with empty (abstract) tiles
    tileMap = new Tile **[MAP_WIDTH];
    for(int i=0;i<MAP_WIDTH;i++){
        tileMap[i] = new Tile*[MAP_HEIGHT];
    }
}

/**
 * Check the collision with any tile of the tilemap and an entity e
 * @param e, the entity to check collision with
 * @return int, a number that represents the tile type
 */
int Map::checkCollision(Entity *e) {
    int result = NO_COLL;
    for(int i = 0; i < MAP_WIDTH; i++){
        for(int j = 0; j < MAP_HEIGHT; j++){
            int type = tileMap[i][j]->getTILETYPE();
            switch (type){
                case POINT_SMALL:
                    //POINT
                    result = e->collision(tileMap[i][j]);
                    if(result && e->getType() == PACMAN){
                        //std::cout << "Point scored!" << std::endl;
                        tileMap[i][j]->setTILETYPE(BLANK);
                        return POINT;
                    }
                    break;
                case POINT_BIG:
                    //BIG point (energize)
                    result = e->collision(tileMap[i][j]);
                    if(result && e->getType() == PACMAN){
                        //std::cout << "Bonus scored!" << std::endl;
                        tileMap[i][j]->setTILETYPE(BLANK);
                        return BONUS;
                    }
                    break;
                case DOOR_HORIZONTAL:
                    result = e->collision(tileMap[i][j]);
                    if(result && e->getType() == PACMAN){
                        return true;
                    }
                case BLANK:
                    //DO nothing
                    break;
                default:
                    //Check regular collision with wall
                    result = e->collision(tileMap[i][j]);

                    if(result){
                        return result;
                    }
                    break;
            }
        }
    }
    return result;
}

/**
 * Checks if the given position is an intersection
 * Intersections means there are multiple options to move to, not only forward
 * @param posX
 * @param posY
 * @return bool, true = on intersection, false = not on intersection
 */
bool Map::isIntersection(int posX, int posY){
    int dir[4][2] = {{0, 1}, {0, -1},
                     {1, 0}, {-1, 0}};
    int j=0;
    //Don't check the border tiles
    if(posX >= this->MAP_WIDTH - 1 || posY >= this->MAP_HEIGHT - 1 || posX < 1 || posY < 1){
        return false;
    }
    for (auto &i : dir) {
        if(tileMap[posX + i[0]][posY + i[1]]->getTILETYPE() == BLANK ||
           tileMap[posX + i[0]][posY + i[1]]->getTILETYPE() == POINT_BIG ||
           tileMap[posX + i[0]][posY + i[1]]->getTILETYPE() == POINT_SMALL ||
           tileMap[(int)posX + i[0]][(int)posY + i[1]]->getTILETYPE() == DOOR_HORIZONTAL){
            j++;
        }
    }

    return j > 2;
}

/**
 * Checks is all points are eaten
 * @return
 */
bool Map::isDone() {
    bool result = true;
    for(int i = 0; i<MAP_WIDTH;i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if(tileMap[i][j]->getTILETYPE() == POINT_SMALL){
                result = false;
            }
        }
    }
    return result;
}

/**
 * @return, the y location of the door
 */
float Map::getDoorY() {
    for(int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            int type = tileMap[i][j]->getTILETYPE();
            if(type == DOOR_HORIZONTAL){
                return tileMap[i][j]->getPosY();
            }
        }
    }
    return 0.0f;
}

/**
 * @return, the x location of the door
 */
float Map::getDoorX() {
    for(int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            int type = tileMap[i][j]->getTILETYPE();
            if(type == DOOR_HORIZONTAL){
                return tileMap[i][j]->getPosX();
            }
        }
    }
    return 0.0f;
}

Tile ***Map::getTileMap() const {
    return tileMap;
}

int Map::getMAP_WIDTH() const {
    return MAP_WIDTH;
}

int Map::getMAP_HEIGHT() const {
    return MAP_HEIGHT;
}
