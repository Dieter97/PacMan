//
// Created by dieter on 26/02/18.
//

#include <iostream>
#include "Ghost.h"

using namespace std;

Ghost::Ghost(int heigth, int width) {
    cout << "Creating Ghost" << endl;
    windowX = heigth;
    windowY = width;
}

void Ghost::move(int deltaX,int deltaY) {
    //TODO CREATE VECTOR MOVEMENT SYSTEM with acceleration and direction
    x = x + deltaX;
    y = y + deltaY;
    if(x>windowX){
        x = -45;
    }
    if(y>windowY){
        y = -45;
    }
    if(x<-45){
        x = windowX;
    }
    if(y<-45){
        y = windowY;
    }
}
