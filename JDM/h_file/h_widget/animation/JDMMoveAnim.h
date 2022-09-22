#include "__manimation.h"
#include "__widget.h"

class MoveAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    float __EXposition;
    float __EYposition;
    float __timer;

public:
    const float oldX;
    const float oldY;

public:
    MoveAnimation(std::shared_ptr<__Widget> widg,
                  const float Xposition, const float Yposition,
                  const float time, const bool AddtoX = false, const bool AddtoY = false)
        : widget(widg), __timer(time),
          oldX(widg->x), oldY(widg->y)
    {
        __EXposition = (AddtoX) ? this->widget->x + Xposition : Xposition;
        __EYposition = (AddtoY) ? this->widget->y + Yposition : Yposition;
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
        static bool SAnimation = [](MoveAnimation *animate)
        {
            animate->startAnimation();
            return true;
        }(this);

        // Set Static Variables
        static float SXposition = this->widget->x;
        static float SYposition = this->widget->y;
        static float Xadder = (widget->x - __EXposition) * (1.0 / (this->__timer * 60));
        static float Yadder = (widget->y - __EYposition) * (1.0 / (this->__timer * 60));
        static float XStopper = std::abs(widget->x - __EXposition);
        static float YStopper = std::abs(widget->y - __EYposition);

        // Check if Ended.
        XStopper -= std::abs(Xadder);
        YStopper -= std::abs(Yadder);
        if (XStopper <= 0 && YStopper <= 0)
        {
            this->endAnimation();
            this->widget->x = __EXposition;
            this->widget->y = __EYposition;
            this->widget->setRect();
            return false;
        }

        // Add Every Frame
        SXposition -= Xadder;
        SYposition -= Yadder;
        this->widget->x = SXposition;
        this->widget->y = SYposition;
        this->WhileAnimation();
        this->widget->setRect();
        return true;
    }
};

class SizeAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    float __EWidth;
    float __EHeight;
    float __timer;

public:
    const float oldWidth;
    const float oldHeight;
    funcCallback startAnimation = []() {};
    funcCallback WhileAnimation = []() {};
    funcCallback endAnimation = []() {};

public:
    SizeAnimation(std::shared_ptr<__Widget> widg,
                  const float Width, const float Height,
                  const float time, const bool AddtoWidth = false, const bool AddtoHeight = false)
        : widget(widg), __timer(time), oldWidth(widg->width), oldHeight(widg->height)
    {
        __EWidth = (AddtoWidth) ? this->widget->width + Width : Width;
        __EHeight = (AddtoHeight) ? this->widget->height + Height : Height;
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
        static bool SAnimation = [](SizeAnimation *animate)
        {
            animate->startAnimation();
            return true;
        }(this);

        // Set Static Variables
        static float SWidth = this->widget->width;
        static float SHeight = this->widget->height;
        static float Wadder = (widget->width - __EWidth) * (1.0 / (this->__timer * 60));
        static float Hadder = (widget->height - __EHeight) * (1.0 / (this->__timer * 60));
        static float WStopper = std::abs(widget->x - __EWidth);
        static float HStopper = std::abs(widget->y - __EHeight);

        // Check if Ended.
        WStopper -= std::abs(Wadder);
        HStopper -= std::abs(Hadder);
        if (WStopper <= 0 && HStopper <= 0)
        {
            this->endAnimation();
            this->widget->width = __EWidth;
            this->widget->height = __EHeight;
            this->widget->setRect();
            return false;
        }

        // Add Every Frame
        SWidth -= Wadder;
        SHeight -= Hadder;
        this->widget->width = SWidth;
        this->widget->height = SHeight;
        this->WhileAnimation();
        this->widget->setRect();
        return true;
    }
};

class ZoomAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    float __EWidth;
    float __EHeight;
    float __timer;

public:
    const float oldX;
    const float oldY;
    const float oldWidth;
    const float oldHeight;
    funcCallback startAnimation = []() {};
    funcCallback WhileAnimation = []() {};
    funcCallback endAnimation = []() {};

public:
    ZoomAnimation(std::shared_ptr<__Widget> widg,
                  const float Width, const float Height,
                  const float time, const bool AddtoWidth = false, const bool AddtoHeight = false)
        : widget(widg), __timer(time),
          oldX(widg->x), oldY(widg->y),
          oldWidth(widg->width), oldHeight(widg->height)
    {
        __EWidth = (AddtoWidth) ? this->widget->width + Width : Width;
        __EHeight = (AddtoHeight) ? this->widget->height + Height : Height;
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
        static bool SAnimation = [](ZoomAnimation *animate)
        {
            animate->startAnimation();
            return true;
        }(this);

        // Set Static Variables
        static float SXposition = this->widget->x;
        static float SYposition = this->widget->y;
        static float SWidth = this->widget->width;
        static float SHeight = this->widget->height;

        static float WXadder = (widget->width - __EWidth) * (1.0 / (this->__timer * 60));
        static float HYadder = (widget->height - __EHeight) * (1.0 / (this->__timer * 60));
        static float WXStopper = std::abs(widget->width - __EWidth);
        static float HYStopper = std::abs(widget->height - __EHeight);

        // Check if Ended.
        WXStopper -= std::abs(WXadder);
        HYStopper -= std::abs(HYadder);
        if (WXStopper <= 0 && HYStopper <= 0)
        {
            this->endAnimation();
            this->widget->width = __EWidth;
            this->widget->height = __EHeight;
            this->widget->x = SXposition - ((__EWidth - this->oldWidth) / 2);
            this->widget->y = SYposition - ((__EHeight - this->oldHeight) / 2);
            this->widget->setRect();
            return false;
        }

        // Add Every Frame
        SWidth -= WXadder;
        SHeight -= HYadder;
        this->widget->width = SWidth;
        this->widget->height = SHeight;
        this->widget->x = SXposition - ((SWidth - this->oldWidth) / 2);
        this->widget->y = SYposition - ((SHeight - this->oldHeight) / 2);
        this->WhileAnimation();
        this->widget->setRect();
        return true;
    }
};
