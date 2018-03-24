//
// Created by dieter on 24/03/18.
//

#ifndef GAMETEST_VIEW_H
#define GAMETEST_VIEW_H


class View {
protected:
    float posX;
    float posY;
    bool visible;

public:
    View(float posX,float posY);
    virtual void visualize() = 0;

    bool isVisible() const;

    void setVisible(bool visible);
};


#endif //GAMETEST_VIEW_H
