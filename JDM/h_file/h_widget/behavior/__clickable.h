#pragma once
#include "__widget.h"
#include "__behavior.h"

class ClickableBehavior : public __Behavior
{
public:
    bool left_click = false;
    bool right_click = false;

    funcCallback left_on_press = []() {};
    funcCallback right_on_press = []() {};
    funcCallback left_on_release = []() {};
    funcCallback right_on_release = []() {};

public:
    void left_mouse_down(__MWidget *widg);
    void left_mouse_up(__MWidget *widg);

    void right_mouse_down(__MWidget *widg);
    void right_mouse_up(__MWidget *widg);
};
