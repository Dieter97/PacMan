//
// Created by dieter on 26/02/18.
//

#include "DirectXFactory.h"
#include "DirectXGhost.h"

Ghost *DirectXFactory::createGhost() {
    return new DirectXGhost();
}
