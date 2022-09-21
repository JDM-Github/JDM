#pragma once
#include "__drag.h"
#include "__moveable.h"

class __Rectangle : public __Widget, public __DragBehavior, public __MoveAbleBehavior
{
public:
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Rectangle(const float width = 100.f, const float height = 100.f,
                const float x = 0.f, const float y = 0.f,
                const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
                const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Rectangle() {}
    void setRandomColor();

protected:
    void setRect();
    void _update();
    void _render();
    void _l_m_down();
    void _l_m_motion();
    void _l_m_up();
    void _r_m_down();
    void _r_m_motion();
    void _r_m_up();

private:
    SDL_FRect __destination;
};
