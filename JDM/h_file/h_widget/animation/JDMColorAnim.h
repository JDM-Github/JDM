#pragma once
#include "__manimation.h"
#include "__widgetcolor.h"

class RGBAAnimation : public __Animation
{
private:
    std::shared_ptr<__WidgetColor> widget;
    Uint8 __R;
    Uint8 __G;
    Uint8 __B;
    Uint8 __A;

    float __SR;
    float __SG;
    float __SB;
    float __SA;
    float __Radder;
    float __Gadder;
    float __Badder;
    float __Aadder;
    float __RStopper;
    float __GStopper;
    float __BStopper;
    float __AStopper;
    float __timer;

public:
    const Uint8 oldR;
    const Uint8 oldG;
    const Uint8 oldB;
    const Uint8 oldA;

public:
    RGBAAnimation(std::shared_ptr<__WidgetColor> widg,
                  const Uint8 R_color, const Uint8 G_color,
                  const Uint8 B_color, const Uint8 A_color, const float timer,
                  const bool AddtoR = false, const bool AddtoG = false,
                  const bool AddtoB = false, const bool AddtoA = false)
        : widget(widg), __timer(timer),
          oldR(widg->R_color), oldG(widg->G_color),
          oldB(widg->B_color), oldA(widg->A_color)
    {
        __R = (AddtoR) ? ((widget->R_color + R_color > 255) ? 255 : widget->R_color + R_color) : R_color;
        __G = (AddtoG) ? ((widget->G_color + G_color > 255) ? 255 : widget->G_color + G_color) : G_color;
        __B = (AddtoB) ? ((widget->B_color + B_color > 255) ? 255 : widget->B_color + B_color) : B_color;
        __A = (AddtoA) ? ((widget->A_color + A_color > 255) ? 255 : widget->A_color + A_color) : A_color;
        this->__SR = this->widget->R_color;
        this->__SG = this->widget->G_color;
        this->__SB = this->widget->B_color;
        this->__SA = this->widget->A_color;
        this->__Radder = (widget->R_color - __R) * (1.0 / (this->__timer * 60));
        this->__Gadder = (widget->G_color - __G) * (1.0 / (this->__timer * 60));
        this->__Badder = (widget->B_color - __B) * (1.0 / (this->__timer * 60));
        this->__Aadder = (widget->A_color - __A) * (1.0 / (this->__timer * 60));
        this->__RStopper = std::abs(widget->R_color - __R);
        this->__GStopper = std::abs(widget->G_color - __G);
        this->__BStopper = std::abs(widget->B_color - __B);
        this->__AStopper = std::abs(widget->A_color - __A);
    }
    bool _update()
    {
        if (this->pauseAnimation)
            return true;
        else if (this->cancelAnimation)
            return false;
        else if (this->widget->parent == nullptr)
            return true;
        __RStopper -= std::abs(__Radder);
        __GStopper -= std::abs(__Gadder);
        __BStopper -= std::abs(__Badder);
        __AStopper -= std::abs(__Aadder);
        if (__RStopper <= 0 && __GStopper <= 0 && __BStopper <= 0 && __Aadder <= 0)
        {
            this->endAnimation();
            this->widget->R_color = __R;
            this->widget->G_color = __G;
            this->widget->B_color = __B;
            this->widget->A_color = __A;
            this->widget->__setColor();
            this->widget->__setOpacity();
            return false;
        }
        __SR -= __Radder;
        __SG -= __Gadder;
        __SB -= __Badder;
        __SA -= __Aadder;
        this->widget->R_color = (Uint8)__SR;
        this->widget->G_color = (Uint8)__SG;
        this->widget->B_color = (Uint8)__SB;
        this->widget->A_color = (Uint8)__SA;
        this->WhileAnimation();
        this->widget->__setColor();
        this->widget->__setOpacity();
        return true;
    }
};
