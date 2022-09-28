#include "JDM.h"
#include "__texture.h"

__Label::__Label(const std::string &_text, const float width,
                 const float height, const float x, const float y,
                 const Uint8 r_color, const Uint8 g_color,
                 const Uint8 b_color, const Uint8 a_color)
    : __text(_text), __Widget(width, height, x, y)
{
    this->behavior["drag"] = std::make_shared<__DragBehavior>();

    this->__initVariables();
    this->R_color = r_color;
    this->G_color = g_color;
    this->B_color = b_color;
    this->A_color = a_color;
    this->__texture = TextureManager::__createTTFTexture(this->__text, this->__font, this->R_color, this->G_color, this->B_color);
    this->__source.x = this->__source.y = 0;
    SDL_QueryTexture(this->__texture, NULL, NULL, &this->__source.w, &this->__source.h);
    SDL_SetTextureBlendMode(this->__texture, SDL_BLENDMODE_BLEND);
    this->__setOpacity();
}

void __Label::__initVariables()
{
    this->__font = "None";
    this->font_size = 16;
    this->Fwidth = false;
    this->Fheight = false;
}

void __Label::setRect()
{
    if (this->parent != nullptr && this->parent->is_layout == false)
        this->_camera_update();
    this->__destination.w = (this->Fwidth) ? this->width : this->__text.length() * this->font_size;
    this->__destination.h = (this->Fheight) ? this->height : this->font_size * 2.5;
    switch (this->halign)
    {
    case Halign::LEFT:
        this->__destination.x = this->x;
        break;
    case Halign::HCENTER:
        this->__destination.x = this->x + ((this->width - this->__destination.w) / 2);
        break;
    case Halign::RIGHT:
        this->__destination.x = this->x + (this->width - this->__destination.w);
        break;
    }
    switch (this->valign)
    {
    case Valign::TOP:
        this->__destination.y = this->y;
        break;
    case Valign::VCENTER:
        this->__destination.y = this->y + ((this->height - this->__destination.h) / 2);
        break;
    case Valign::BOTTOM:
        this->__destination.y = this->y + (this->height - this->__destination.h);
        break;
    }
}

void __Label::__changeLabel() { this->__texture = TextureManager::__createTTFTexture(this->__text, this->__font, this->R_color, this->G_color, this->B_color); }
void __Label::__setColor() { SDL_SetTextureColorMod(this->__texture, this->R_color, this->G_color, this->B_color); }
void __Label::__setOpacity() { SDL_SetTextureAlphaMod(this->__texture, this->A_color); }

void __Label::_update()
{
    __Widget::_update();
    this->setRect();
    this->__setColor();
    this->__setOpacity();
}

void __Label::changeText(const std::string &text)
{
    this->__text = text;
    this->__changeLabel();
}

void __Label::changeFont(const std::string &font)
{
    this->__font = font;
    this->__changeLabel();
}

std::string __Label::getText() const { return this->__text; }
void __Label::_render() { SDL_RenderCopyF(JDM::renderer, this->__texture, &this->__source, &this->__destination); }
void __Label::setRandomColor() { __ColorManager::__SetRandomColor(this->R_color, this->G_color, this->A_color); }
