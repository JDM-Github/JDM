#include "JDM.h"

/* Initialize Movement Key. */
__MoveAbleBehavior::__MoveAbleBehavior()
    : up_key(JDM::W_key), down_key(JDM::S_key), left_key(JDM::A_key),
      right_key(JDM::D_key), boost_key(JDM::space_key) {}

/**
 * @brief Moveable method used to Move Widget.
 *
 * @param Widget*
 */
void __MoveAbleBehavior::move_widget(__Widget *widg)
{
    if (this->control_widget)
    {
        widg->camera_related = false;
        if (!(widg->bind_in_parent))
        {
            float adder = (this->boost_key) ? this->boost_speed : this->normal_speed;
            if (this->up_key && this->down_key == false)
                if (JDM::control_camera)
                    JDM::camera_y += adder;
                else
                {
                    widg->y -= adder;
                    if (this->limit_control)
                        if (widg->parent->height >= widg->height)
                        {
                            if (widg->y <= widg->parent->y)
                                widg->y = widg->parent->y;
                        }
                        else
                            widg->y += adder;
                }
            else if (this->down_key && this->up_key == false)
                if (JDM::control_camera)
                    JDM::camera_y -= adder;
                else
                {
                    widg->y += adder;
                    if (this->limit_control)
                        if (widg->parent->height >= widg->height)
                        {
                            if (widg->y + widg->height >= widg->parent->y + widg->parent->height)
                                widg->y = (widg->parent->y + widg->parent->height) - widg->height;
                        }
                        else
                            widg->y -= adder;
                }
            if (this->left_key && this->right_key == false)
                if (JDM::control_camera)
                    JDM::camera_x += adder;
                else
                {
                    widg->x -= adder;
                    if (this->limit_control)
                        if (widg->parent->width >= widg->width)
                        {
                            if (widg->x <= widg->parent->x)
                                widg->x = widg->parent->x;
                        }
                        else
                            widg->x += adder;
                }
            else if (this->right_key && this->left_key == false)
                if (JDM::control_camera)
                    JDM::camera_x -= adder;
                else
                {
                    widg->x += adder;
                    if (this->limit_control)
                        if (widg->parent->width >= widg->width)
                        {
                            if (widg->x + widg->width >= widg->parent->x + widg->parent->width)
                                widg->x = (widg->parent->x + widg->parent->width) - widg->width;
                        }
                        else
                            widg->x -= adder;
                }
        }
    }
}
