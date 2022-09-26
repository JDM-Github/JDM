#include "JDM.h"
#include "__texture.h"

__Circle::__Circle(const float radiusX, const float radiusY,
                   const float x, const float y,
                   const Uint8 r_color, const Uint8 g_color,
                   const Uint8 b_color, const Uint8 a_color)
    : __Widget(width, height, x, y)
{
    this->radius_x = radiusX;
    this->radius_y = radiusY;
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
    this->__c_t = TextureManager::__createTexture("assets/circleempty.png");
    SDL_SetTextureBlendMode(this->__c_t, SDL_BLENDMODE_BLEND);
}

void __Circle::setRect()
{
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
    this->__c_r.x = this->x - this->radius_x;
    this->__c_r.y = this->y - this->radius_y;
    this->__c_r.w = this->width;
    this->__c_r.h = this->height;
}

void __Circle::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }
void __Circle::__setColor() { SDL_SetTextureColorMod(this->__c_t, this->R_color, this->G_color, this->B_color); }
void __Circle::__setOpacity() { SDL_SetTextureAlphaMod(this->__c_t, this->A_color); }

void __Circle::_update()
{
    __Widget::_update();
    this->width = this->radius_x * 2;
    this->height = this->radius_y * 2;
    this->setRect();
    this->__setColor();
    this->__setOpacity();
}

void __Circle::_render() { SDL_RenderCopyF(JDM::renderer, this->__c_t, 0, &this->__c_r); }
