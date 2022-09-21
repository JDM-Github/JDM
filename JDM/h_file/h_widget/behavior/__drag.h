#pragma once
#include "__widget.h"

class __DragBehavior
{
public:
    bool left_grab = false;
    bool right_grab = false;

protected:
    void left_mouse_down(const __Widget *widg);
    void left_mouse_motion(__Widget *widg);
    void left_mouse_up();
    void right_mouse_down(const __Widget *widg);
    void right_mouse_motion(__Widget *widg);
    void right_mouse_up();

private:
    bool __left_grabbing = false;
    bool __right_grabbing = false;
    float __left_grab_x = 0.f;
    float __left_grab_y = 0.f;
    float __right_grab_x = 0.f;
    float __right_grab_y = 0.f;
};
