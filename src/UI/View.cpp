//
// Created by dieter on 24/03/18.
//

#include "../../include/logic/View.h"
using namespace logic;

View::View(float posX, float posY) : posX(posX),posY(posY){
    visible = true;
}

bool View::isVisible() const {
    return visible;
}

void View::setVisible(bool visible) {
    View::visible = visible;
}
