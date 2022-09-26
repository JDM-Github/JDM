#include "JDMColorAnim.h"

RGBAAnimation::RGBAAnimation(std::shared_ptr<__Widget> widg,
                             const Uint8 R_color, const Uint8 G_color,
                             const Uint8 B_color, const Uint8 A_color,
                             const float Rtimer, const float Gtimer,
                             const float Btimer, const float Atimer,
                             const bool AddtoR, const bool AddtoG,
                             const bool AddtoB, const bool AddtoA)
    : widget(dynamic_cast<__WidgetColor *>(&*widg)), oldR(widget->R_color), oldG(widget->G_color),
      oldB(widget->B_color), oldA(widget->A_color)
{
    if (widget->currentAnim.find(RGBAANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        __R = (AddtoR) ? ((widget->R_color + R_color > 255) ? 255 : widget->R_color + R_color) : R_color;
        __G = (AddtoG) ? ((widget->G_color + G_color > 255) ? 255 : widget->G_color + G_color) : G_color;
        __B = (AddtoB) ? ((widget->B_color + B_color > 255) ? 255 : widget->B_color + B_color) : B_color;
        __A = (AddtoA) ? ((widget->A_color + A_color > 255) ? 255 : widget->A_color + A_color) : A_color;
        this->__SR = this->widget->R_color;
        this->__SG = this->widget->G_color;
        this->__SB = this->widget->B_color;
        this->__SA = this->widget->A_color;
        this->__Radder = (widget->R_color - __R) * (1.0 / (Rtimer * 60));
        this->__Gadder = (widget->G_color - __G) * (1.0 / (Gtimer * 60));
        this->__Badder = (widget->B_color - __B) * (1.0 / (Btimer * 60));
        this->__Aadder = (widget->A_color - __A) * (1.0 / (Atimer * 60));
        this->__RStopper = std::abs(widget->R_color - __R);
        this->__GStopper = std::abs(widget->G_color - __G);
        this->__BStopper = std::abs(widget->B_color - __B);
        this->__AStopper = std::abs(widget->A_color - __A);
    }
}

bool RGBAAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
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
        this->widget->currentAnim.erase(RGBAANIMATION);
        return false;
    }
    if (!(__RStopper <= 0))
        __SR -= __Radder;
    else
        __SR = __R;
    if (!(__GStopper <= 0))
        __SG -= __Gadder;
    else
        __SG = __G;
    if (!(__BStopper <= 0))
        __SB -= __Badder;
    else
        __SB = __B;
    if (!(__AStopper <= 0))
        __SA -= __Aadder;
    else
        __SA = __A;
    this->widget->R_color = (Uint8)__SR;
    this->widget->G_color = (Uint8)__SG;
    this->widget->B_color = (Uint8)__SB;
    this->widget->A_color = (Uint8)__SA;
    this->WhileAnimation();
    this->widget->__setColor();
    this->widget->__setOpacity();
    return true;
}