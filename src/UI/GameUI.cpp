//
// Created by dieter on 24/03/18.
//

#include "GameUI.h"

void GameUI::addView(std::string key,View *view) {
    GameUI::views.emplace(key,view);
}

void GameUI::visualize() {
    for(auto& view : views){
        view.second->visualize();
    }
}

GameUI::GameUI() = default;
