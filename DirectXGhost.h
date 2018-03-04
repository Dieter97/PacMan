//
// Created by dieter on 26/02/18.
//

#ifndef GAMETEST_DIRECTXGHOST_H
#define GAMETEST_DIRECTXGHOST_H


#include "Ghost.h"

class DirectXGhost : public Ghost{
public:
    DirectXGhost();

    void visualize() override;
};


#endif //GAMETEST_DIRECTXGHOST_H
