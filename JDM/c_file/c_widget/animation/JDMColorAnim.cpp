#include "JDMColorAnim.h"
#include "JDMAnimate.h"

RGBAAnimation::RGBAAnimation(std::shared_ptr<__Widget> widg,
                             const Uint8 R_color, const Uint8 G_color,
                             const Uint8 B_color, const Uint8 A_color,
                             const float Rtimer, const float Gtimer,
                             const float Btimer, const float Atimer)

    : widget(dynamic_cast<__WidgetColor *>(&*widg)),
      oldR(widget->R_color), oldG(widget->G_color),
      oldB(widget->B_color), oldA(widget->A_color)
{
    target[0] = &widget->R_color;
    target[1] = &widget->G_color;
    target[2] = &widget->B_color;
    target[3] = &widget->A_color;
    JDMAnimate::initVariables(widget, flag, RGBAANIMATION, target,
                              adder, start, stopper, end,
                              {R_color, G_color, B_color, A_color},
                              {Rtimer, Gtimer, Btimer, Atimer});
}

bool RGBAAnimation::_update()
{
    return JDMAnimate::setAnimate(
        adder, stopper, start, end, widget, this, target, RGBAANIMATION,
        std::bind(
            [](__WidgetColor &widget)
            {
                widget.__setColor();
                widget.__setOpacity();
            },
            *widget));
}

RAnimation::RAnimation(std::shared_ptr<__Widget> widg, const Uint8 R_color, const float timer)
    : __ColorAnimation(widg, R_color, RED_CANIMATION), oldR(widget->R_color)
{
    target = &widget->R_color;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}

GAnimation::GAnimation(std::shared_ptr<__Widget> widg, const Uint8 G_color, const float timer)
    : __ColorAnimation(widg, G_color, GREEN_CANIMATION), oldG(widget->G_color)
{
    target = &widget->G_color;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}

BAnimation::BAnimation(std::shared_ptr<__Widget> widg, const Uint8 B_color, const float timer)
    : __ColorAnimation(widg, B_color, BLUE_CANIMATION), oldB(widget->B_color)
{
    target = &widget->B_color;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}

AAnimation::AAnimation(std::shared_ptr<__Widget> widg, const Uint8 A_color, const float timer)
    : __ColorAnimation(widg, A_color, ALPHA_CANIMATION), oldA(widget->A_color)
{
    target = &widget->A_color;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}
