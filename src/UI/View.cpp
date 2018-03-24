//
// Created by dieter on 24/03/18.
//

#include "View.h"

View::View(float posX, float posY) : posX(posX),posY(posY){

}

bool View::isVisible() const {
    return visible;
}

void View::setVisible(bool visible) {
    View::visible = visible;
}
