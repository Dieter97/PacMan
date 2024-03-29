//
// Created by dieter on 08/06/18.
//

#include "../../include/logic/Button.h"
#include "../../include/logic/Game.h"
using namespace logic;

Button::Button(float posX, float posY) : View(posX, posY), fontSize(12) {
    View::visible = true;
    Button::action = nullptr;
}

Button::Button(float posX, float posY, std::string string, int fontSize, Function action) : View(posX, posY), fontSize(fontSize) {
    Button::text = string;
    View::visible = true;
    Button::action = action;
}

/**
 * Executes a the given action when the button is selected
 * @param g, the class containing the functions
 */
void Button::onClick(Game *g) {
    if (Button::selected) {
        //Execute the given action
        Button::action(g);
    }
}

const std::string &Button::getText() const {
    return Button::text;
}

void Button::setText(const std::string &text) {
    Button::text = text;
}

void Button::select() {
    Button::selected = true;
    Button::setText(Button::text + "<---");
}

void Button::unselect() {
    Button::selected = false;
    //Remove first and last char
    Button::text = Button::text.substr(0, Button::text.size()-4);
}

bool Button::isSelected() {
    return Button::selected;
}
