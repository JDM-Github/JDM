#pragma once
#include "__manimation.h"
#include "__widgetcolor.h"

class RGBAAnimation : public __Animation
{
private:
    bool Flag = true;
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

public:
    const Uint8 oldR;
    const Uint8 oldG;
    const Uint8 oldB;
    const Uint8 oldA;

public:
    RGBAAnimation(std::shared_ptr<__WidgetColor> widg,
                  const Uint8 R_color, const Uint8 G_color,
                  const Uint8 B_color, const Uint8 A_color,
                  const float Rtimer = 1, const float Gtimer = 1,
                  const float Btimer = 1, const float Atimer = 1,
                  const bool AddtoR = false, const bool AddtoG = false,
                  const bool AddtoB = false, const bool AddtoA = false);
    bool _update();
};
