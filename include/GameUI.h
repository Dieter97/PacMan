//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_GAMEUI_H
#define GAMETEST_GAMEUI_H


#include <map>
#include <string>
#include "View.h"
#include "TextView.h"
#include "Button.h"

class GameUI {
protected:
    std::map<std::string,TextView*> textViews;
    std::map<std::string,Button*> buttons;

public:
    GameUI();
    void visualize();
    void addTextView(std::string key,TextView* view);
    bool removeTextView(std::string key);
    void changeTextView(std::string key, std::string text);
    void addButton(std::string key,Button* btn);
    bool removeButton(std::string key);
    void onClick(Game *g);
    void removeAllUI();
};


#endif //GAMETEST_GAMEUI_H
