#include "JDM.h"

__Line::__Line(const float x1, const float y1,
               const float x_2, const float y_2,
               const Uint8 r_color, const Uint8 g_color,
               const Uint8 b_color, const Uint8 a_color)
    : __WidgetColor(width, height, x1, y1)
{
    this->x2 = x_2;
    this->y2 = y_2;
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
}

void __Line::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }

void __Line::_update()
{
    __Widget::_update();
    this->width = 1.f;
    this->height = 1.f;
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
}

void __Line::_render()
{
    SDL_SetRenderDrawColor(JDM::renderer, this->R_color, this->G_color, this->B_color, this->A_color);
    SDL_RenderDrawLineF(JDM::renderer, this->x, this->y, this->x2, this->y2);
}
