#pragma once
#include "__widgetcolor.h"

class __Circle : public __WidgetColor
{
public:
    float radius_x;
    float radius_y;
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Circle(const float radiusX = 50.f, const float radiusY = 50.f,
             const float x = 50.f, const float y = 50.f,
             const Uint8 r_color = 0xFF, const Uint8 g_color = 0xFF,
             const Uint8 b_color = 0xFF, const Uint8 a_color = 0xFF);
    ~__Circle() {}

    void setRandomColor();

protected:
    void setRect();
    void _render();
    void _update();

private:
    SDL_Texture *__c_t;
    SDL_FRect __c_r;

private:
    void __setColor();
    void __setOpacity();
};