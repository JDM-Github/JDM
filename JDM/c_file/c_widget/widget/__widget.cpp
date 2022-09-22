#include "JDM.h"

__Widget::__Widget(const float w, const float h, const float x_position, const float y_position)
{
    this->width = w;
    this->height = h;
    this->x = x_position;
    this->y = y_position;
    this->__initVariables();
    this->__update_position();
}

void __Widget::__update_position()
{
    this->__width = this->width;
    this->__height = this->height;
    this->__x = this->x;
    this->__y = this->y;
}

void __Widget::__initVariables()
{
    this->size_hint_x = 1.f;
    this->size_hint_y = 1.f;
    this->velocity_x = 0.f;
    this->velocity_y = 0.f;
}

void __Widget::add_widget(std::shared_ptr<__Widget> widg)
{
    this->children.emplace_back(widg);
    widg->parent = this;
}

void __Widget::remove_widget(std::shared_ptr<__Widget> widg)
{
    auto position = std::find(this->children.begin(), this->children.end(), widg);
    if (position != this->children.end())
    {
        this->children.erase(position);
        widg->parent = nullptr;
    }
}

void __Widget::_camera_update()
{
    if (this->camera_related)
    {
        this->x += JDM::camera_x - this->__temp_camera_x;
        this->y += JDM::camera_y - this->__temp_camera_y;
        this->_back_camera();
    }
}

void __Widget::_back_camera()
{
    this->__temp_camera_x = JDM::camera_x;
    this->__temp_camera_y = JDM::camera_y;
}

void __Widget::_update()
{
    this->__set_position();
    if (this->camera_related == false)
        this->_back_camera();
    this->updateFunc();
}

void __Widget::_islayout()
{
    if (this->is_layout)
        this->layout_Func();
}

void __Widget::_loopEvent(std::shared_ptr<__Widget> widg, __Widget::TypeLoop type)
{
    for (auto children : widg->children)
    {
        switch (type)
        {
        case UPDATE:
            children->_update();
            break;
        case RENDER:
            children->_render();
            break;
        case L_M_DOWN:
            children->_l_m_down();
            break;
        case L_M_MOTION:
            children->_l_m_motion();
            break;
        case L_M_UP:
            children->_l_m_up();
            break;
        case R_M_DOWN:
            children->_r_m_down();
            break;
        case R_M_MOTION:
            children->_r_m_motion();
            break;
        case R_M_UP:
            children->_r_m_up();
            break;
        case ISLAYOUT:
            children->_islayout();
            break;
        }
        children->_loopEvent(children, type);
    }
}
