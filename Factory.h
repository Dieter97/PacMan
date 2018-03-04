//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_FACTORY_H
#define GAMETEST_FACTORY_H


#include "Ghost.h"

class Factory {
public:
    virtual Ghost* createGhost() = 0;
    virtual bool initDisplay() = 0;
    virtual void close() = 0;
};


#endif //GAMETEST_FACTORY_H
