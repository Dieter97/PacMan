//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_TYPES_H
#define GAMETEST_TYPES_H


enum Directions{
    DIR_RIGHT,
    DIR_LEFT,
    DIR_DOWN,
    DIR_UP
};

enum GhostColor{
    RED_GHOST,
    PINK_GHOST,
    BLUE_GHOST,
    ORANGE_GHOST
};

enum Events
{
    KEY_PRESS_QUIT,
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

#endif //GAMETEST_TYPES_H
