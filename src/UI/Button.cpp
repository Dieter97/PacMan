//
// Created by dieter on 08/06/18.
//

#include "../../include/Button.h"

Button::Button(float posX, float posY) : View(posX, posY), fontSize(12) {
    View::visible = true;
    Button::action = nullptr;
}

const std::string &Button::getText() const {
    return Button::text;
}

void Button::setText(const std::string &text) {
    Button::text = text;
}

Button::Button(float posX, float posY, std::string string, int fontSize, Function action) : View(posX, posY), fontSize(fontSize) {
    Button::text = string;
    View::visible = true;
    Button::action = action;
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

void Button::onClick() {
    if(Button::selected) {
        //Execute the given action
        Button::action();
    }
}
