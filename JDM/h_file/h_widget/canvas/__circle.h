#pragma once
#include "__widget.h"

class __Circle : public __Widget
{
public:
    float radius;
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Circle(const float radius = 100.f,
             const float x = 0.f, const float y = 0.f,
             const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
             const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Circle() {}

    void setRandomColor();

protected:
    void _render();
    void _update();
};