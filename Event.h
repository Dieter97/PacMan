//
// Created by dieter on 05/03/18.
//

#ifndef GAMETEST_EVENT_H
#define GAMETEST_EVENT_H


class Event {
public:
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
public:
    virtual int getEvent() = 0;

};


#endif //GAMETEST_EVENT_H
