//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_GAMEUI_H
#define GAMETEST_GAMEUI_H


#include <map>
#include <string>
#include "View.h"
#include "TextView.h"

class GameUI {
protected:
    std::map<std::string,TextView*> textViews;

public:
    GameUI();
    void visualize();
    void addTextView(std::string key,TextView* view);
    bool removeTextView(std::string key);
    void changeText(std::string key,std::string text);
};


#endif //GAMETEST_GAMEUI_H
