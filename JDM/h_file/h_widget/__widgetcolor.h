#pragma once
#include "__widget.h"

class __WidgetColor : virtual public __Widget
{
public:
    Uint8 R_color = 255,
          G_color = 255,
          B_color = 255,
          A_color = 255;

public:
    virtual void __setColor() {}
    virtual void __setOpacity() {}
};
