#include "JDM.h"

__Rectangle::__Rectangle(const float width, const float height,
                         const float x, const float y,
                         const Uint8 r_color, const Uint8 g_color,
                         const Uint8 b_color, const Uint8 a_color)
    : __Widget(width, height, x, y)
{
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
}

void __Rectangle::_update()
{
    __MoveAbleBehavior::move_widget(this);
    __Widget::_update();
    this->setRect();
}

void __Rectangle::_render()
{
    SDL_SetRenderDrawColor(JDM::renderer, this->R_color, this->G_color, this->B_color, this->A_color);
    SDL_RenderFillRectF(JDM::renderer, &this->__destination);
}

void __Rectangle::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }
void __Rectangle::setRect()
{
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
    this->__destination.w = this->width;
    this->__destination.h = this->height;
    this->__destination.x = this->x;
    this->__destination.y = this->y;
}

void __Rectangle::_l_m_down()
{
    __DragBehavior::left_mouse_down(this);
    this->l_m_down_Func();
}

void __Rectangle::_l_m_motion()
{
    __DragBehavior::left_mouse_motion(this);
    this->l_m_motion_Func();
}

void __Rectangle::_l_m_up()
{
    __DragBehavior::left_mouse_up();
    this->l_m_up_Func();
}

void __Rectangle::_r_m_down()
{
    __DragBehavior::right_mouse_down(this);
    this->r_m_down_Func();
}
void __Rectangle::_r_m_motion()
{
    __DragBehavior::right_mouse_motion(this);
    this->r_m_motion_Func();
}

void __Rectangle::_r_m_up()
{
    __DragBehavior::right_mouse_up();
    this->r_m_up_Func();
}
