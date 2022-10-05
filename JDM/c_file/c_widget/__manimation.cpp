#include "__manimation.h"
#include "JDMAnimate.h"

__ColorAnimation::__ColorAnimation(std::shared_ptr<__Widget> widg, const Uint8 End, const int FLAG)
    : widget(dynamic_cast<__WidgetColor *>(&*widg)), end(End), TFLAG(FLAG) {}

bool __ColorAnimation::_update()
{
    return JDMAnimate::Animate(
        adder, stopper, start, end, widget, this, *target, TFLAG,
        std::bind(
            [](__WidgetColor &widget)
            {
                widget.__setColor();
                widget.__setOpacity();
            },
            *widget));
}

__InitAnimation::__InitAnimation(std::shared_ptr<__Widget> widg, const float End, const int FLAG)
    : widget(&*widg), end(End), TFLAG(FLAG) {}

bool __InitAnimation::_update()
{
    return JDMAnimate::Animate(
        adder, stopper, start, end, widget, this, *target, TFLAG,
        std::bind(
            [](__Widget &widget)
            {
                widget.setRect();
            },
            *widget));
}
