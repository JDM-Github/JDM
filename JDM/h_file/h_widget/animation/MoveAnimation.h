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
    funcCallback startAnimation = []() {};
    funcCallback WhileAnimation = []() {};
    funcCallback endAnimation = []() {};

public:
    MoveAnimation(std::shared_ptr<__Widget> widg, const float Xposition, const float Yposition, const float time, const bool AddtoWidget = false)
        : widget(widg), __timer(time)
    {
        if (AddtoWidget)
        {
            __EXposition = this->widget->x + Xposition;
            __EYposition = this->widget->y + Yposition;
        }
        else
        {
            __EXposition = Xposition;
            __EYposition = Yposition;
        }
    }

    bool _update()
    {
        // Pause Animation is True
        if (pauseAnimation)
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
            Log(this->widget->x, " ", this->widget->y);
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
