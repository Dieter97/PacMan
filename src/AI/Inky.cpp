//
// Created by dieter on 18/03/18.
//

#include <cmath>
#include <algorithm>
#include <map>

#include "../../include/Inky.h"
#include "../../include/Types.h"

int Inky::getNextDirection(float posX,float posY, int mode) {
    int direction = -1;
    float targetX = target->getPosX();
    float targetY = target->getPosY();
    switch (mode){
        case SCATTERING:
            //Move to selected scatter point
            direction = calculateShortest(posX,posY,map->getMAP_WIDTH()+10,map->getMAP_HEIGHT()+10);
            break;
        case CHASING:
            //Move to target: chasing 2 tile in front of target
            switch (target->getDIRECTION()){
                case DIR_UP:
                    direction = calculateShortest(posX,posY,targetX,targetY-2);
                    break;
                case DIR_DOWN:
                    direction = calculateShortest(posX,posY,targetX,targetY+2);
                    break;
                case DIR_LEFT:
                    direction = calculateShortest(posX,posY,targetX-2,targetY);
                    break;
                case DIR_RIGHT:
                    direction = calculateShortest(posX,posY,targetX+2,targetY);
                    break;
                default:
                    //noting
                    break;
            }
            break;
        case FLEE:
            //Random decision
            direction= rand() % 4;
            break;
        case DEAD:
            //Move to spawn
            direction = calculateShortest(posX,posY,spawnX,spawnY);
            break;
        default:
            //Nothing
            break;
    }

    return direction;
}

int Inky::calculateShortest(float x1,float y1,float x2,float y2){
    int dir[4][2] = {{0,1},{0,-1},
                     {1,0},{-1,0}};
    int res = -1;
    std::map<float,int> distances;
    float locX,locY;
    Tile *** tileMap = this->map->getTileMap();

    //first calculate all distances in the available directions
    for(auto &i : dir){
        if(tileMap[(int)x1+ i[0]][(int)y1+ i[1]]->getTILETYPE() == BLANK ||
           tileMap[(int)x1+ i[0]][(int)y1+ i[1]]->getTILETYPE() == POINT_BIG ||
           tileMap[(int)x1+ i[0]][(int)y1+ i[1]]->getTILETYPE() == POINT_SMALL) {
            locX = x1 + i[0];
            locY = y1 + i[1];
            if (i[0] == 0) {
                //UP OR DOWN
                if (i[1] == -1) {
                    res = DIR_UP;
                } else {
                    res = DIR_DOWN;
                }
            } else {
                //LEFT OF RIGHT
                if (i[0] == -1) {
                    res = DIR_LEFT;
                } else {
                    res = DIR_RIGHT;
                }
            }
            distances.emplace((float) std::sqrt(((locX - x2) * (locX - x2)) + ((locY - y2) * (locY - y2))),res);
        }
    }


    res = distances.begin()->second;
    //Don't allow the ghost to go back
    switch (prev_dir) {
        case DIR_RIGHT:
            if(res == DIR_LEFT){
                distances.erase(distances.begin()->first);
                res = distances.begin()->second;
            }
            break;
        case DIR_UP:
            if(res == DIR_DOWN){
                distances.erase(distances.begin()->first);
                res = distances.begin()->second;
            }
            break;
        case DIR_LEFT:
            if(res == DIR_RIGHT){
                distances.erase(distances.begin()->first);
                res = distances.begin()->second;
            }
            break;
        case DIR_DOWN:
            if(res == DIR_UP){
                distances.erase(distances.begin()->first);
                res = distances.begin()->second;
            }
            break;
        default:
            //nothing
            break;
    }
    prev_dir = res;
    return res;
}

Inky::Inky(Map *m,int x,int y,MovingEntity*t) : AI(m,x,y,t) {}