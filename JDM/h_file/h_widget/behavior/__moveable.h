#pragma once
#include "__widget.h"
#include "__behavior.h"

class __MoveAbleBehavior : public __Behavior
{
public:
    __MoveAbleBehavior();
    __Widget *limit = nullptr;
    float normal_speed = 4.f;
    float boost_speed = 6.f;
    bool control_widget = false;
    bool &up_key;
    bool &down_key;
    bool &left_key;
    bool &right_key;
    bool &boost_key;

protected:
    void update(__MWidget *widg);
};
