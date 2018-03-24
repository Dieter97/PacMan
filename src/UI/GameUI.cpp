//
// Created by dieter on 24/03/18.
//

#include "../../include/GameUI.h"
#include "../../include/TextView.h"

void GameUI::addTextView(std::string key,TextView *view) {
    GameUI::textViews.emplace(key,view);
}

void GameUI::visualize() {
    for(auto& view : textViews){
        view.second->visualize();
    }
}

bool GameUI::removeTextView(std::string key) {
    return GameUI::textViews.erase(key) != 0;
}

void GameUI::changeText(std::string key, std::string text) {
    GameUI::textViews.at(key)->setText(text);
}

GameUI::GameUI() = default;
