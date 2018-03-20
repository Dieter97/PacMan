//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_TYPES_H
#define GAMETEST_TYPES_H


enum STATES{
    DIR_RIGHT,
    DIR_LEFT,
    DIR_DOWN,
    DIR_UP,
    SPAWNING,
    DEFAULT
};

enum GhostColor{
    RED_GHOST,
    PINK_GHOST,
    BLUE_GHOST,
    ORANGE_GHOST
};

enum Events {
    KEY_PRESS_QUIT,
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

enum CollisionEvents {
    NO_COLL,
    COLL,
    POINT,
    BONUS
};

enum TilesTypes{
    FULL_DOWN_RIGHT,
    FULL_DOWN,
    FULL_DOWN_LEFT,
    WALL_VERTICAL,
    WALL_DOWN_RIGHT,
    WALL_DOWN_END,
    FULL_RIGHT,
    FULL_CENTERED,
    FULL_LEFT,
    WALL_TOP_END,
    WALL_TOP_RIGHT,
    WALL_T_TOP,
    FULL_TOP_RIGHT,
    FULL_TOP,
    FULL_TOP_LEFT,
    FULL_WALL_TOP_LEFT,
    WALL_LEFT_DOWN,
    WALL_RIGHT_END,
    POINT_SMALL,
    POINT_BIG,
    FULL_T_DOWN,
    WALL_HORIZONTAL,
    WALL_LEFT_TOP,
    WALL_LEFT_END,
    FULL_WALL_TOP_RIGHT,
    DOOR_HORIZONTAL,
    FULL_WALL_DOWN_LEFT,
    FULL_WALL_DOWN_RIGHT,
    FULL_T_TOP,
    WALL_T_DOWN,
    BLANK,
    PLAYER_SPAWN,
    RED_GHOST_SPAWN,
    PINK_GHOST_SPAWN,
    BLUE_GHOST_SPAWN,
    ORANGE_GHOST_SPAWN
};

enum EntityType{
    PACMAN,
    GHOST,
    TILE
};

enum TileColor{
    BLUE_TILE,
    PINK_TILE,
    ORANGE_TILE
};
#endif //GAMETEST_TYPES_H
