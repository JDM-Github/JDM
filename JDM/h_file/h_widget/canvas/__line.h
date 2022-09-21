#pragma once
#include "__widget.h"

class __Line : public __Widget
{
public:
    float x2, y2;
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Line(const float x1 = 0.f, const float y1 = 0.f,
           const float x2 = 100.f, const float y2 = 100.f,
           const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
           const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Line() {}
    void setRandomColor();

protected:
    void _update();
    void _render();
};
