#include "__manimation.h"

class XAnimation : public __InitAnimation
{
public:
    const float oldX;
    XAnimation(std::shared_ptr<__Widget> widg, const float X, const float timer = 1);
};

class YAnimation : public __InitAnimation
{
public:
    const float oldY;
    YAnimation(std::shared_ptr<__Widget> widg, const float Y, const float timer = 1);
};
