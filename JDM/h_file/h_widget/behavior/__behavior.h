#pragma once
#include "__mwidget.h"

class __Behavior
{
public:
    virtual void update(__MWidget *widg) {}
    virtual void left_mouse_down(__MWidget *widg) {}
    virtual void left_mouse_motion(__MWidget *widg) {}
    virtual void left_mouse_up(__MWidget *widg) {}
    virtual void right_mouse_down(__MWidget *widg) {}
    virtual void right_mouse_motion(__MWidget *widg) {}
    virtual void right_mouse_up(__MWidget *widg) {}
};
