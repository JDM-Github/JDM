#pragma once
#include "__drag.h"
#include "__moveable.h"

class __Image : public __Widget, public __DragBehavior, public __MoveAbleBehavior
{
public:
    std::string sourcefile;
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Image(const std::string &source = "None", const float width = 100.f,
            const float height = 100.f, const float x = 0.f, const float y = 0.f,
            const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
            const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Image() { SDL_DestroyTexture(this->__texture); }
    void setRandomColor();

protected:
    void setRect();
    void _render();
    void _update();
    void _l_m_down();
    void _l_m_motion();
    void _l_m_up();
    void _r_m_down();
    void _r_m_motion();
    void _r_m_up();

private:
    SDL_Texture *__texture;
    SDL_Rect __source;
    SDL_FRect __destination;

private:
    void __setColor();
    void __setOpacity();
};
