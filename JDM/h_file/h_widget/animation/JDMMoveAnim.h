#include "__manimation.h"
#include "__widget.h"

struct Position
{
    float __EX, __EY;
    float __SX, __SY;
    float __XAdder, __YAdder;
    float __XStopper, __YStopper;
};

struct Size
{
    float __EW, __EH;
    float __SW, __SH;
    float __WAdder, __HAdder;
    float __WStopper, __HStopper;
};

class MoveAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    Position position;

public:
    const float oldX;
    const float oldY;

public:
    MoveAnimation(std::shared_ptr<__Widget> widg,
                  const float Xposition, const float Yposition,
                  const float Xtimer = 1, const float Ytimer = 1,
                  const bool AddtoX = false, const bool AddtoY = false);
    bool _update();
};

class SizeAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    Size size;

public:
    const float oldWidth;
    const float oldHeight;

public:
    SizeAnimation(std::shared_ptr<__Widget> widg,
                  const float Width, const float Height,
                  const float Wtimer = 1, const float Htimer = 1,
                  const bool AddtoWidth = false, const bool AddtoHeight = false);
    bool _update();
};

class ZoomAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    Size size;
    float __SX;
    float __SY;

public:
    const float oldX;
    const float oldY;
    const float oldWidth;
    const float oldHeight;

public:
    ZoomAnimation(std::shared_ptr<__Widget> widg,
                  const float Width, const float Height,
                  const float Wtimer = 1, const float Htimer = 1,
                  const bool AddtoWidth = false, const bool AddtoHeight = false);
    bool _update();
};

class MoveSizeAnimation : public __Animation
{
private:
    std::shared_ptr<__Widget> widget;
    Position position;
    Size size;

public:
    const float oldX;
    const float oldY;
    const float oldWidth;
    const float oldHeight;

public:
    MoveSizeAnimation(std::shared_ptr<__Widget> widg,
                      const float Width, const float Height,
                      const float Xposition, const float Yposition,
                      const float Xtimer = 1, const float Ytimer = 1,
                      const float Wtimer = 1, const float Htimer = 1,
                      const bool AddtoX = false, const bool AddtoY = false,
                      const float AddtoWidth = false, const float AddtoHeight = false);
    bool _update();
};
