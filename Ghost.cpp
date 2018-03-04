//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "Ghost.h"

using namespace std;

Ghost::Ghost() {
    cout << "Creating Ghost" << endl;
}

void Ghost::move(int deltaX,int deltaY) {
    x = x + deltaX;
    y = y + deltaY;

}
