#include "JDM.h"

void __DragBehavior::left_mouse_down(__MWidget *widg)
{
    if (widg->collide_point(JDM::mouseX, JDM::mouseY))
    {
        this->__left_grabbing = true;
        if (this->left_grab && this->__left_grabbing)
        {
            this->__left_grab_x = widg->x - JDM::mouseX;
            this->__left_grab_y = widg->y - JDM::mouseY;
        }
    }
}

void __DragBehavior::left_mouse_motion(__MWidget *widg)
{
    if (this->left_grab && this->__left_grabbing)
    {
        widg->x = JDM::mouseX + this->__left_grab_x;
        widg->y = JDM::mouseY + this->__left_grab_y;
    }
}

void __DragBehavior::left_mouse_up(__MWidget *widg)
{
    if (this->__left_grabbing)
        this->__left_grabbing = false;
}

void __DragBehavior::right_mouse_down(__MWidget *widg)
{
    if (widg->collide_point(JDM::mouseX, JDM::mouseY))
    {
        this->__right_grabbing = true;
        if (this->right_grab && this->__right_grabbing)
        {
            this->__right_grab_x = widg->x - JDM::mouseX;
            this->__right_grab_y = widg->y - JDM::mouseY;
        }
    }
}

void __DragBehavior::right_mouse_motion(__MWidget *widg)
{
    if (this->right_grab && this->__right_grabbing)
    {
        widg->x = JDM::mouseX + this->__right_grab_x;
        widg->y = JDM::mouseY + this->__right_grab_y;
    }
}

void __DragBehavior::right_mouse_up(__MWidget *widg)
{
    if (this->__right_grabbing)
        this->__right_grabbing = false;
}
