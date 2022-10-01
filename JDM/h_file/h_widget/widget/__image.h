#pragma once
#include "__drag.h"
#include "__moveable.h"
#include "__widgetcolor.h"

class __Image : public __WidgetColor
{
public:
    std::string sourcefile;

    double angle = 0;
    SDL_FPoint *point = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

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

private:
    SDL_Texture *__texture;
    SDL_Rect __source;
    SDL_FRect __destination;

public:
    void __setColor();
    void __setOpacity();
};
