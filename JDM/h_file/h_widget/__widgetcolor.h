#pragma once
#include "__widget.h"

class __WidgetColor : virtual public __Widget
{
public:
    Uint8 R_color, G_color, B_color, A_color;

public:
    virtual void __setColor() {}
    virtual void __setOpacity() {}
};
