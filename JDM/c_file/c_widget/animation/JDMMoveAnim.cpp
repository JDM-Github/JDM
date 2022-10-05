#include "JDMMoveAnim.h"
#include "JDMAnimate.h"

XAnimation::XAnimation(std::shared_ptr<__Widget> widg, const float X, const float timer)
    : __InitAnimation(widg, X, XANIMATION), oldX(widget->x)
{
    target = &widget->x;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}

YAnimation::YAnimation(std::shared_ptr<__Widget> widg, const float Y, const float timer)
    : __InitAnimation(widg, Y, YANIMATION), oldY(widget->y)
{
    target = &widget->y;
    JDMAnimate::initVariable(widget, flag, TFLAG, target, adder, start, stopper, end, timer);
}
