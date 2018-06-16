//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_TEXTVIEW_H
#define GAMETEST_TEXTVIEW_H


#include "View.h"
#include <string>

namespace logic {
    class TextView : public View {
    protected:
        std::string text;
        int fontSize;
    public:
        TextView(float posX, float posY);

        TextView(float posX, float posY, std::string string, int fontSize);

        const std::string &getText() const;

        void setText(const std::string &text);
    };
}


#endif //GAMETEST_TEXTVIEW_H
