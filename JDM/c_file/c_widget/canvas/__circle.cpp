#include "JDM.h"

__Circle::__Circle(const float radius_,
                   const float x, const float y,
                   const Uint8 r_color, const Uint8 g_color,
                   const Uint8 b_color, const Uint8 a_color)
    : __Widget(width, height, x, y)
{
    this->radius = radius_;
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
}

void __Circle::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }

void __Circle::_update()
{
    __Widget::_update();
    this->width = this->radius * 2;
    this->height = this->radius * 2;
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
}

void __Circle::_render()
{
    SDL_SetRenderDrawColor(JDM::renderer, this->R_color, this->G_color, this->B_color, this->A_color);
    for (size_t h = 0; h != this->radius * 2; h++)
    {
        for (size_t w = 0; w != this->radius * 2; w++)
        {
            float vy = h - this->radius;
            float vx = w - this->radius;
            if (((vx * vx) + (vy * vy)) <= this->radius * this->radius)
                SDL_RenderDrawPointF(JDM::renderer, this->x + vx, this->y + vy);
        }
    }
}
