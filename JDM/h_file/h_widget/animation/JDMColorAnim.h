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
    }

    bool _update()
    {
        // Pause Animation is True
        if (pauseAnimation)
            return true;
        else if (cancelAnimation)
            return false;
        else if (this->widget->parent == nullptr)
            return true;

        // Call Start Animation
        static bool SAnimation = [](RGBAAnimation *animate)
        {
            animate->startAnimation();
            return true;
        }(this);

        // Set Static Variables
        static float SR = this->widget->R_color;
        static float SG = this->widget->G_color;
        static float SB = this->widget->B_color;
        static float SA = this->widget->A_color;

        static float Radder = (widget->R_color - __R) * (1.0 / (this->__timer * 60));
        static float Gadder = (widget->G_color - __G) * (1.0 / (this->__timer * 60));
        static float Badder = (widget->B_color - __B) * (1.0 / (this->__timer * 60));
        static float Aadder = (widget->A_color - __A) * (1.0 / (this->__timer * 60));

        static float RStopper = std::abs(widget->R_color - __R);
        static float GStopper = std::abs(widget->G_color - __G);
        static float BStopper = std::abs(widget->B_color - __B);
        static float AStopper = std::abs(widget->A_color - __A);

        // Check if Ended.
        RStopper -= std::abs(Radder);
        GStopper -= std::abs(Gadder);
        BStopper -= std::abs(Badder);
        AStopper -= std::abs(Aadder);
        if (RStopper <= 0 && GStopper <= 0 && BStopper <= 0 && Aadder <= 0)
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

        // Add Every Frame
        SR -= Radder;
        SG -= Gadder;
        SB -= Badder;
        SA -= Aadder;
        this->widget->R_color = (Uint8)SR;
        this->widget->G_color = (Uint8)SG;
        this->widget->B_color = (Uint8)SB;
        this->widget->A_color = (Uint8)SA;
        this->WhileAnimation();
        this->widget->__setColor();
        this->widget->__setOpacity();
        return true;
    }
};
