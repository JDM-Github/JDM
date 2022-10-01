#pragma once
#include "__widget.h"

class __WidgetColor : public __Widget
{
public:
    Uint8 R_color = 255,
          G_color = 255,
          B_color = 255,
          A_color = 255;

public:
    __WidgetColor(float width = 100.f, float height = 100.f, float x = 0.f, float y = 0.f) : __Widget(width, height, x, y) {}
    virtual void __setColor() {}
    virtual void __setOpacity() {}
};
