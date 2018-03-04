//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_DIRECTXFACTORY_H
#define GAMETEST_DIRECTXFACTORY_H


#include "Factory.h"

class DirectXFactory : public Factory{
    Ghost* createGhost() override;
};


#endif //GAMETEST_DIRECTXFACTORY_H
