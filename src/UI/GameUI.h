//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_GAMEUI_H
#define GAMETEST_GAMEUI_H


#include <map>
#include <string>
#include "View.h"

class GameUI {
protected:
    std::map<std::string,View*> views;

public:
    GameUI();
    void visualize();
    void addView(std::string key,View* view);
};


#endif //GAMETEST_GAMEUI_H
