#include "JDM.h"

__MoveAbleBehavior::__MoveAbleBehavior()
    : up_key(JDM::W_key), down_key(JDM::S_key), left_key(JDM::A_key),
      right_key(JDM::D_key), boost_key(JDM::space_key) {}

void __MoveAbleBehavior::update(__MWidget *widg)
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
                    if (this->limit != nullptr)
                        if (limit->height >= widg->height)
                        {
                            if (widg->y <= limit->y)
                                widg->y = limit->y;
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
                    if (this->limit != nullptr)
                        if (limit->height >= widg->height)
                        {
                            if (widg->y + widg->height >= limit->y + limit->height)
                                widg->y = (limit->y + limit->height) - widg->height;
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
                    if (this->limit != nullptr)
                        if (limit->width >= widg->width)
                        {
                            if (widg->x <= limit->x)
                                widg->x = limit->x;
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
                    if (this->limit != nullptr)
                        if (limit->width >= widg->width)
                        {
                            if (widg->x + widg->width >= limit->x + limit->width)
                                widg->x = (limit->x + limit->width) - widg->width;
                        }
                        else
                            widg->x -= adder;
                }
        }
    }
}
