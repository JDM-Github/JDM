#pragma once
#include "__widget.h"

/**
 * Widget Behavior:
 *  -> Allow widget to be control with Keys binded into them.
 *
 * How to use?:
 *  -> To use this behavior, you need to override update method
 *  --- and call MoveAbleBehavior::move_widget() method.
 */
class __MoveAbleBehavior
{
public:
    __MoveAbleBehavior();
    float normal_speed = 4.f;
    float boost_speed = 6.f;
    bool control_widget = false;
    bool limit_control = false;
    bool &up_key;
    bool &down_key;
    bool &left_key;
    bool &right_key;
    bool &boost_key;

protected:
    void move_widget(__Widget *widg);
};
