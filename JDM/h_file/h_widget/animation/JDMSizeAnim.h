#pragma once
#include "__manimation.h"

class WAnimation : public __InitAnimation
{
public:
    const float oldWidth;
    WAnimation(std::shared_ptr<__Widget> widg, const float W, const float timer = 1);
};

class HAnimation : public __InitAnimation
{
public:
    const float oldHeight;
    HAnimation(std::shared_ptr<__Widget> widg, const float H, const float timer = 1);
};
