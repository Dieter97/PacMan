//
// Created by dieter on 24/03/18.
//

#include "TextView.h"


TextView::TextView(float posX, float posY) : View(posX, posY), fontSize(12) {
    View::visible = true;
}


TextView::TextView(float posX, float posY, std::string string, int fontSize) :
        View(posX,posY),fontSize(fontSize) {
    TextView::text = string;
    View::visible = true;
}

const std::string &TextView::getText() const {
    return text;
}

void TextView::setText(const std::string &text) {
    TextView::text = text;
}