//
// Created by dieter on 08/06/18.
//

#ifndef GAMETEST_BUTTON_H
#define GAMETEST_BUTTON_H

#include "View.h"
#include "Types.h"
#include <string>

class Button : public View {
protected:
    std::string text;
    int fontSize;
    Function action;
    bool selected = false;
public:
    Button(float posX, float posY);
    Button(float posX, float posY, std::string string, int fontSize,Function action);
    const std::string &getText() const;
    void setText(const std::string &text);
    void select();
    void unselect();
    void onClick();
};

#endif //GAMETEST_BUTTON_H
