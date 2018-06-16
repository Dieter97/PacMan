//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_SDLFACTORY_H
#define GAMETEST_SDLFACTORY_H

#include "../logic/Factory.h"
#include <iostream>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDLContext.h"
#include "../Types.h"

namespace SDL {
    class SDLFactory : public logic::Factory {

    private:
        //The window we'll be rendering to
        SDL_Window *gWindow;
        //The window renderer
        SDL_Renderer *gRenderer = nullptr;
        //Current displayed texture
        SDL_Texture *gTexture = nullptr;
        //TTF
        TTF_Font *gFont = nullptr;

        SDLContext *context;

        //Windwow parameters
        static const int WINDOW_WIDTH = 1200;
        static const int WINDOW_HEIGTH = 900;

        //Tile parameters
        static const int tileHeight = 15;
        static const int tileWidth = 15;

    public:
        logic::Ghost *createGhost(float posX, float posY, float speed, int color) override;

        logic::PacMan *createPacMan(float posX, float posY, float speed) override;

        logic::Tile *createTile(float posX, float posY, int tileType, int tileColor) override;

        logic::Event *createEventSystem() override;

        logic::Map *createMap(int width, int height) override;

        bool initDisplay(int mapWidth, int mapHeight) override;

        bool loadMedia() override;

        logic::TextView *createTextView(float posX, float posY, std::string string, int fontSize);

        logic::Button *createButton(float posX, float posY, std::string string, int fontSize, logic::Function action) override;

        logic::Timer *createTimer();

        void close() override;

        void render() override;

        void clear() override;

        virtual ~SDLFactory();
    };
}

#endif //GAMETEST_SDLFACTORY_H
