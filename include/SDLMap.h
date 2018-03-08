//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_SDLMAP_H
#define GAMETEST_SDLMAP_H


#include "Map.h"
#include "SDLContext.h"

class SDLMap : public Map{
public:

    SDLMap(int width, int height, int tileWidth, int tileHeight, SDLContext *context);

    void visualize() override ;
    void loadMap(int** map,int COLOR) override ;
private:
    SDLContext* context;


};


#endif //GAMETEST_SDLMAP_H
