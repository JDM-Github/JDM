#include "JDM.h"
#include "__clickable.h"

__Button::__Button(const float width, const float height,
                   const float x, const float y,
                   const Uint8 r_color, const Uint8 g_color,
                   const Uint8 b_color, const Uint8 a_color)
    : __WidgetColor(width, height, x, y)
{
    this->behavior["button"] = std::make_shared<ClickableBehavior>();
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
}

void __Button::_update()
{
    __Widget::_update();
    this->setRect();
}

void __Button::_render()
{
    SDL_SetRenderDrawColor(JDM::renderer, this->R_color, this->G_color, this->B_color, this->A_color);
    SDL_RenderFillRectF(JDM::renderer, &this->__destination);
}

void __Button::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }
void __Button::setRect()
{
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
    this->__destination.w = this->width;
    this->__destination.h = this->height;
    this->__destination.x = this->x;
    this->__destination.y = this->y;
}
