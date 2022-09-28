#include "JDM.h"
#include "__clickable.h"

void ClickableBehavior::left_mouse_down(__MWidget *widg)
{
    if (widg->collide_point(JDM::mouseX, JDM::mouseY))
    {
        left_click = true;
        this->left_on_press();
    }
}

void ClickableBehavior::right_mouse_down(__MWidget *widg)
{
    if (widg->collide_point(JDM::mouseX, JDM::mouseY))
    {
        right_click = true;
        this->right_on_press();
    }
}

void ClickableBehavior::left_mouse_up(__MWidget *widg)
{
    if (left_click)
    {
        left_click = false;
        this->left_on_release();
    }
}

void ClickableBehavior::right_mouse_up(__MWidget *widg)
{
    if (right_click)
    {
        right_click = false;
        this->right_on_release();
    }
}
