//
// Created by dieter on 7/03/18.
//

#ifndef GAMETEST_SDLMAP_H
#define GAMETEST_SDLMAP_H


#include "../logic/Map.h"
#include "SDLContext.h"

namespace SDL {
    class SDLMap : public logic::Map {
    public:

        SDLMap(int width, int height, SDLContext *context);

        void visualize() override;

        void loadMap(int **map, int COLOR) override;

    private:
        SDLContext *context;

    };

}
#endif //GAMETEST_SDLMAP_H
