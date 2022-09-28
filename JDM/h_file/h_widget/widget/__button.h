#pragma once
#include "__widgetcolor.h"
#include "__clickable.h"

class __Button : public __WidgetColor
{
public:
    __Button(const float width = 100.f, const float height = 100.f,
             const float x = 0.f, const float y = 0.f,
             const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
             const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Button() {}
    void setRandomColor();

protected:
    void setRect();
    void _update();
    void _render();

private:
    SDL_FRect __destination;
};
