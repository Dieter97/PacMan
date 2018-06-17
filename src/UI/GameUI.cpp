//
// Created by dieter on 24/03/18.
//

#include "../../include/logic/GameUI.h"

using namespace logic;

GameUI::GameUI() = default;

/**
 * Passed the click event to the buttons
 * @param g
 */
void GameUI::onClick(Game *g) {
    Button *selected = nullptr;
    for (auto &view : buttons) {
        if (view.second->isSelected()) {
            selected = view.second;
            break;
        }
    }
    if (selected != nullptr) {
        selected->onClick(g);
    }
}

void GameUI::visualize() {
    for(auto& view : textViews){
        view.second->visualize();
    }
    for(auto& view : buttons){
        view.second->visualize();
    }
}

void GameUI::addTextView(std::string key, TextView *view) {
    GameUI::textViews.emplace(key, view);
}

bool GameUI::removeTextView(std::string key) {
    return GameUI::textViews.erase(key) != 0;
}

void GameUI::changeTextView(std::string key, std::string text) {
    GameUI::textViews.at(key)->setText(text);
}

void GameUI::addButton(std::string key, Button *btn) {
    GameUI::buttons.emplace(key,btn);
}

bool GameUI::removeButton(std::string key) {
    return GameUI::buttons.erase(key) != 0;
}

void GameUI::removeAllUI() {
    this->buttons.clear();
    this->textViews.clear();
}
