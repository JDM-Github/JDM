#include "JDMSizeAnim.h"
#include "JDMAnimate.h"

WAnimation::WAnimation(std::shared_ptr<__Widget> widg, const float W, const float timer)
    : __InitAnimation(widg, W, WANIMATION), oldWidth(widget->width)
{
    target = &widget->width;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}

HAnimation::HAnimation(std::shared_ptr<__Widget> widg, const float H, const float timer)
    : __InitAnimation(widg, H, HANIMATION), oldHeight(widget->height)
{
    target = &widget->height;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}
