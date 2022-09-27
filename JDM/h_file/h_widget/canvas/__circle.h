#pragma once
#include "__widgetcolor.h"

class __Circle : public __WidgetColor
{
public:
    float radius;
    Uint8 R_color, G_color, B_color, A_color;

public:
    __Circle(const float radiusXY = 50.f,
             const float x = 0.f, const float y = 0.f,
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