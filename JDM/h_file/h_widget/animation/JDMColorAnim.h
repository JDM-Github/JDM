#pragma once
#include "__manimation.h"
#include "__widgetcolor.h"

class RGBAAnimation : public __Animation
{
private:
    __WidgetColor *widget;
    std::array<Uint8, 4> end;
    std::array<Uint8 *, 4> target;
    std::array<float, 4> start;
    std::array<float, 4> adder;
    std::array<float, 4> stopper;

public:
    const Uint8 oldR;
    const Uint8 oldG;
    const Uint8 oldB;
    const Uint8 oldA;

public:
    RGBAAnimation(std::shared_ptr<__Widget> widg,
                  const Uint8 R_color, const Uint8 G_color,
                  const Uint8 B_color, const Uint8 A_color,
                  const float Rtimer = 1, const float Gtimer = 1,
                  const float Btimer = 1, const float Atimer = 1);
    bool _update();
};

class RAnimation : public __ColorAnimation
{
public:
    const Uint8 oldR;
    RAnimation(std::shared_ptr<__Widget> widg, const Uint8 R_color, const float timer = 1);
};

class GAnimation : public __ColorAnimation
{
public:
    const Uint8 oldG;
    GAnimation(std::shared_ptr<__Widget> widg, const Uint8 G_color, const float timer = 1);
};

class BAnimation : public __ColorAnimation
{
public:
    const Uint8 oldB;
    BAnimation(std::shared_ptr<__Widget> widg, const Uint8 B_color, const float timer = 1);
};

class AAnimation : public __ColorAnimation
{
public:
    const Uint8 oldA;
    AAnimation(std::shared_ptr<__Widget> widg, const Uint8 A_color, const float timer = 1);
};
