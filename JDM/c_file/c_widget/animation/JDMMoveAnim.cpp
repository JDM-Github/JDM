#include "JDMMoveAnim.h"

XAnimation::XAnimation(std::shared_ptr<__Widget> widg,
                       const float Xposition, const float Xtimer, const bool AddtoX)
    : widget(widg), oldX(widg->x)
{
    if (widget->currentAnim.find(XANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(XANIMATION);
        this->position.__SX = this->widget->x;
        this->position.__EX = (AddtoX) ? this->widget->x + Xposition : Xposition;
        this->position.__XAdder = (this->widget->x - this->position.__EX) * (1.0 / (Xtimer * 60));
        this->position.__XStopper = std::abs(this->widget->x - this->position.__EX);
    }
}

bool XAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->position.__XStopper -= std::abs(this->position.__XAdder);
    if (this->position.__XStopper <= 0)
    {
        this->endAnimation();
        this->widget->x = this->position.__EX;
        this->widget->setRect();
        this->widget->currentAnim.erase(XANIMATION);
        return false;
    }
    this->position.__SX -= this->position.__XAdder;
    this->widget->x = this->position.__SX;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

YAnimation::YAnimation(std::shared_ptr<__Widget> widg,
                       const float Yposition, const float Ytimer, const bool AddtoY)
    : widget(widg), oldY(widg->y)
{
    if (widget->currentAnim.find(YANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(YANIMATION);
        this->position.__SY = this->widget->y;
        this->position.__EY = (AddtoY) ? this->widget->y + Yposition : Yposition;
        this->position.__YAdder = (this->widget->y - this->position.__EY) * (1.0 / (Ytimer * 60));
        this->position.__YStopper = std::abs(this->widget->y - this->position.__EY);
    }
}

bool YAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->position.__YStopper -= std::abs(this->position.__YAdder);
    if (this->position.__YStopper <= 0)
    {
        this->endAnimation();
        this->widget->y = this->position.__EY;
        this->widget->setRect();
        this->widget->currentAnim.erase(YANIMATION);
        return false;
    }
    this->position.__SY -= this->position.__YAdder;
    this->widget->y = this->position.__SY;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

MoveAnimation::MoveAnimation(std::shared_ptr<__Widget> widg,
                             const float Xposition, const float Yposition,
                             const float Xtimer, const float Ytimer,
                             const bool AddtoX, const bool AddtoY)
    : widget(widg), oldX(widg->x), oldY(widg->y)
{
    if (widget->currentAnim.find(MOVEANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(MOVEANIMATION);
        this->position.__SX = this->widget->x;
        this->position.__SY = this->widget->y;
        this->position.__EX = (AddtoX) ? this->widget->x + Xposition : Xposition;
        this->position.__EY = (AddtoY) ? this->widget->y + Yposition : Yposition;
        this->position.__XAdder = (this->widget->x - this->position.__EX) * (1.0 / (Xtimer * 60));
        this->position.__YAdder = (this->widget->y - this->position.__EY) * (1.0 / (Ytimer * 60));
        this->position.__XStopper = std::abs(this->widget->x - this->position.__EX);
        this->position.__YStopper = std::abs(this->widget->y - this->position.__EY);
    }
}

bool MoveAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->position.__XStopper -= std::abs(this->position.__XAdder);
    this->position.__YStopper -= std::abs(this->position.__YAdder);
    if (this->position.__XStopper <= 0 && this->position.__YStopper <= 0)
    {
        this->endAnimation();
        this->widget->x = this->position.__EX;
        this->widget->y = this->position.__EY;
        this->widget->setRect();
        this->widget->currentAnim.erase(MOVEANIMATION);
        return false;
    }
    if (!(this->position.__XStopper <= 0))
        this->position.__SX -= this->position.__XAdder;
    else
        this->position.__SX = this->position.__EX;
    if (!(this->position.__YStopper <= 0))
        this->position.__SY -= this->position.__YAdder;
    else
        this->position.__SY = this->position.__EY;

    this->widget->x = this->position.__SX;
    this->widget->y = this->position.__SY;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

WidthAnimation::WidthAnimation(std::shared_ptr<__Widget> widg,
                               const float Width, const float Wtimer,
                               const bool AddtoWidth)
    : widget(widg), oldWidth(widg->width)
{
    if (widget->currentAnim.find(WANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(WANIMATION);
        this->size.__SW = this->widget->width;
        this->size.__EW = (AddtoWidth) ? this->widget->width + Width : Width;
        this->size.__WAdder = (this->widget->width - this->size.__EW) * (1.0 / (Wtimer * 60));
        this->size.__WStopper = std::abs(this->widget->width - this->size.__EW);
    }
}

bool WidthAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->size.__WStopper -= std::abs(this->size.__WAdder);
    if (this->size.__WStopper <= 0)
    {
        this->endAnimation();
        this->widget->width = this->size.__EW;
        this->widget->setRect();
        this->widget->currentAnim.erase(WANIMATION);
        return false;
    }
    this->size.__SW -= this->size.__WAdder;
    this->widget->width = this->size.__SW;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

HeightAnimation::HeightAnimation(std::shared_ptr<__Widget> widg,
                                 const float Height, const float Htimer,
                                 const bool AddtoHeight)
    : widget(widg), oldHeight(widg->height)
{
    if (widget->currentAnim.find(HANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(HANIMATION);
        this->size.__SH = this->widget->height;
        this->size.__EH = (AddtoHeight) ? this->widget->height + Height : Height;
        this->size.__HAdder = (this->widget->height - this->size.__EH) * (1.0 / (Htimer * 60));
        this->size.__HStopper = std::abs(this->widget->height - this->size.__EH);
    }
}

bool HeightAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->size.__HStopper -= std::abs(this->size.__HAdder);
    if (this->size.__HStopper <= 0)
    {
        this->endAnimation();
        this->widget->height = this->size.__EH;
        this->widget->setRect();
        this->widget->currentAnim.erase(HANIMATION);
        return false;
    }
    this->size.__SH -= this->size.__HAdder;
    this->widget->height = this->size.__SH;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

SizeAnimation::SizeAnimation(std::shared_ptr<__Widget> widg,
                             const float Width, const float Height,
                             const float Wtimer, const float Htimer,
                             const bool AddtoWidth, const bool AddtoHeight)
    : widget(widg), oldWidth(widg->width), oldHeight(widg->height)
{
    if (widget->currentAnim.find(SIZEANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(SIZEANIMATION);
        this->size.__SW = this->widget->width;
        this->size.__SH = this->widget->height;
        this->size.__EW = (AddtoWidth) ? this->widget->width + Width : Width;
        this->size.__EH = (AddtoHeight) ? this->widget->height + Height : Height;
        this->size.__WAdder = (this->widget->width - this->size.__EW) * (1.0 / (Wtimer * 60));
        this->size.__HAdder = (this->widget->height - this->size.__EH) * (1.0 / (Htimer * 60));
        this->size.__WStopper = std::abs(this->widget->width - this->size.__EW);
        this->size.__HStopper = std::abs(this->widget->height - this->size.__EH);
    }
}

bool SizeAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->size.__WStopper -= std::abs(this->size.__WAdder);
    this->size.__HStopper -= std::abs(this->size.__HAdder);
    if (this->size.__WStopper <= 0 && this->size.__HStopper <= 0)
    {
        this->endAnimation();
        this->widget->width = this->size.__EW;
        this->widget->height = this->size.__EH;
        this->widget->setRect();
        this->widget->currentAnim.erase(SIZEANIMATION);
        return false;
    }
    if (!(this->size.__WStopper <= 0))
        this->size.__SW -= this->size.__WAdder;
    else
        this->size.__SW = this->size.__EW;
    if (!(this->size.__HStopper <= 0))
        this->size.__SH -= this->size.__HAdder;
    else
        this->size.__SH = this->size.__EH;
    this->widget->width = this->size.__SW;
    this->widget->height = this->size.__SH;
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

ZoomAnimation::ZoomAnimation(std::shared_ptr<__Widget> widg,
                             const float Width, const float Height,
                             const float Wtimer, const float Htimer,
                             const bool AddtoWidth, const bool AddtoHeight)
    : widget(widg), oldX(widg->x), oldY(widg->y),
      oldWidth(widg->width), oldHeight(widg->height)
{
    if (widget->currentAnim.find(ZOOMANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(ZOOMANIMATION);
        this->size.__EW = (AddtoWidth) ? this->widget->width + Width : Width;
        this->size.__EH = (AddtoHeight) ? this->widget->height + Height : Height;
        this->__SX = this->widget->x;
        this->__SY = this->widget->y;
        this->size.__SW = this->widget->width;
        this->size.__SH = this->widget->height;
        this->size.__WAdder = (widget->width - this->size.__EW) * (1.0 / (Wtimer * 60));
        this->size.__HAdder = (widget->height - this->size.__EH) * (1.0 / (Htimer * 60));
        this->size.__WStopper = std::abs(widget->width - this->size.__EW);
        this->size.__HStopper = std::abs(widget->height - this->size.__EH);
    }
}

bool ZoomAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->size.__WStopper -= std::abs(this->size.__WAdder);
    this->size.__HStopper -= std::abs(this->size.__HAdder);
    if (this->size.__WStopper <= 0 && this->size.__HStopper <= 0)
    {
        this->endAnimation();
        this->widget->width = this->size.__EW;
        this->widget->height = this->size.__EH;
        this->widget->x = this->__SX - ((this->size.__EW - this->oldWidth) / 2);
        this->widget->y = this->__SY - ((this->size.__EH - this->oldHeight) / 2);
        this->widget->setRect();
        this->widget->currentAnim.erase(ZOOMANIMATION);
        return false;
    }
    if (!(this->size.__WStopper <= 0))
        this->size.__SW -= this->size.__WAdder;
    else
        this->size.__SW = this->size.__EW;
    if (!(this->size.__HStopper <= 0))
        this->size.__SH -= this->size.__HAdder;
    else
        this->size.__SH = this->size.__EH;
    this->widget->width = this->size.__SW;
    this->widget->height = this->size.__SH;
    this->widget->x = this->__SX - ((this->size.__SW - this->oldWidth) / 2);
    this->widget->y = this->__SY - ((this->size.__SH - this->oldHeight) / 2);
    this->WhileAnimation();
    this->widget->setRect();
    return true;
}

MoveSizeAnimation::MoveSizeAnimation(std::shared_ptr<__Widget> widg,
                                     const float Width, const float Height,
                                     const float Xposition, const float Yposition,
                                     const float Xtimer, const float Ytimer,
                                     const float Wtimer, const float Htimer,
                                     const bool AddtoX, const bool AddtoY,
                                     const float AddtoWidth, const float AddtoHeight)
    : widget(widg), oldX(widg->x), oldY(widg->y),
      oldWidth(widg->width), oldHeight(widg->height)
{
    if (widget->currentAnim.find(MOVESIZEANIMATION) != widget->currentAnim.end())
        this->Flag = false;
    else
    {
        this->widget->currentAnim.insert(MOVESIZEANIMATION);
        this->size.__EW = (AddtoWidth) ? this->widget->width + Width : Width;
        this->size.__EH = (AddtoHeight) ? this->widget->height + Height : Height;
        this->position.__EX = (AddtoX) ? this->widget->x + Xposition : Xposition;
        this->position.__EY = (AddtoY) ? this->widget->y + Yposition : Yposition;
        this->size.__SW = this->widget->width;
        this->size.__SH = this->widget->height;
        this->position.__SX = this->widget->x;
        this->position.__SY = this->widget->y;
        this->size.__WAdder = (widget->width - this->size.__EW) * (1.0 / (Wtimer * 60));
        this->size.__HAdder = (widget->height - this->size.__EH) * (1.0 / (Htimer * 60));
        this->size.__WStopper = std::abs(widget->width - this->size.__EW);
        this->size.__HStopper = std::abs(widget->height - this->size.__EH);
        this->position.__XAdder = (this->widget->x - this->position.__EX) * (1.0 / (Xtimer * 60));
        this->position.__YAdder = (this->widget->y - this->position.__EY) * (1.0 / (Ytimer * 60));
        this->position.__XStopper = std::abs(this->widget->x - this->position.__EX);
        this->position.__YStopper = std::abs(this->widget->y - this->position.__EY);
    }
}

bool MoveSizeAnimation::_update()
{
    if (this->Flag == false)
        return false;
    else if (this->pauseAnimation)
        return true;
    else if (this->cancelAnimation)
        return false;
    else if (this->widget->parent == nullptr)
        return true;
    this->size.__WStopper -= std::abs(this->size.__WAdder);
    this->size.__HStopper -= std::abs(this->size.__HAdder);
    this->position.__XStopper -= std::abs(this->position.__XAdder);
    this->position.__YStopper -= std::abs(this->position.__YAdder);

    if (this->size.__WStopper <= 0 && this->size.__HStopper <= 0 && this->position.__XStopper <= 0 && this->position.__YStopper <= 0)
    {
        this->endAnimation();
        this->widget->width = this->size.__EW;
        this->widget->height = this->size.__EH;
        this->widget->x = this->position.__EX;
        this->widget->y = this->position.__EY;
        this->widget->setRect();
        this->widget->currentAnim.erase(MOVESIZEANIMATION);
        return false;
    }

    if (!(this->size.__WStopper <= 0))
        this->size.__SW -= this->size.__WAdder;
    else
        this->size.__SW = this->size.__EW;
    if (!(this->size.__HStopper <= 0))
        this->size.__SH -= this->size.__HAdder;
    else
        this->size.__SH = this->size.__EH;
    if (!(this->position.__XStopper <= 0))
        this->position.__SX -= this->position.__XAdder;
    else
        this->position.__SX = this->position.__EX;
    if (!(this->position.__YStopper <= 0))
        this->position.__SY -= this->position.__YAdder;
    else
        this->position.__SY = this->position.__EY;

    this->widget->x = this->position.__SX;
    this->widget->y = this->position.__SY;
    this->widget->width = this->size.__SW;
    this->widget->height = this->size.__SH;

    this->WhileAnimation();
    this->widget->setRect();
    return true;
}
