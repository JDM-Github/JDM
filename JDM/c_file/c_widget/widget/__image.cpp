#include "__texture.h"
#include "JDM.h"

__Image::__Image(const std::string &source, const float width,
                 const float height, const float x, const float y,
                 const Uint8 r_color, const Uint8 g_color,
                 const Uint8 b_color, const Uint8 a_color)
    : __Widget(width, height, x, y)
{
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;

    this->sourcefile = (checkExist(source)) ? source : "None";
    this->__texture = (checkExist(source)) ? TextureManager::__createTexture(source) : TextureManager::__createTexture("C:\\JDM\\assets\\empty.png");
    this->__source.x = this->__source.y = 0;
    SDL_QueryTexture(this->__texture, NULL, NULL, &this->__source.w, &this->__source.h);

    SDL_SetTextureBlendMode(this->__texture, SDL_BLENDMODE_BLEND);
    this->setRect();
    this->__setColor();
    this->__setOpacity();
}

void __Image::__setColor() { SDL_SetTextureColorMod(this->__texture, this->R_color, this->G_color, this->B_color); }
void __Image::__setOpacity() { SDL_SetTextureAlphaMod(this->__texture, this->A_color); }

void __Image::setRect()
{
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
    this->__destination.w = this->width;
    this->__destination.h = this->height;
    this->__destination.x = this->x;
    this->__destination.y = this->y;
}

void __Image::_update()
{
    __MoveAbleBehavior::move_widget(this);
    __Widget::_update();
    this->setRect();
    this->__setColor();
    this->__setOpacity();
}

void __Image::_render() { SDL_RenderCopyF(JDM::renderer, this->__texture, &this->__source, &this->__destination); }
void __Image::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }

void __Image::_l_m_down()
{
    __DragBehavior::left_mouse_down(this);
    this->l_m_down_Func();
}

void __Image::_l_m_motion()
{
    __DragBehavior::left_mouse_motion(this);
    this->l_m_motion_Func();
}

void __Image::_l_m_up()
{
    __DragBehavior::left_mouse_up();
    this->l_m_up_Func();
}

void __Image::_r_m_down()
{
    __DragBehavior::right_mouse_down(this);
    this->r_m_down_Func();
}
void __Image::_r_m_motion()
{
    __DragBehavior::right_mouse_motion(this);
    this->r_m_motion_Func();
}

void __Image::_r_m_up()
{
    __DragBehavior::right_mouse_up();
    this->r_m_up_Func();
}
