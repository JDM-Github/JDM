#pragma once
#include "__widget.h"
#include "__behavior.h"

class __DragBehavior : public __Behavior
{
public:
    bool left_grab = false;
    bool right_grab = false;

protected:
    void left_mouse_down(__MWidget *widg);
    void left_mouse_motion(__MWidget *widg);
    void left_mouse_up(__MWidget *widg);
    void right_mouse_down(__MWidget *widg);
    void right_mouse_motion(__MWidget *widg);
    void right_mouse_up(__MWidget *widg);

private:
    bool __left_grabbing = false;
    bool __right_grabbing = false;
    float __left_grab_x = 0.f;
    float __left_grab_y = 0.f;
    float __right_grab_x = 0.f;
    float __right_grab_y = 0.f;
};
