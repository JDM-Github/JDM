#include "JDM.h"

__StackLayout::__StackLayout(const float width, const float height,
                             const float x, const float y)
    : __MLayout(width, height, x, y)
{
    this->__initVariables();
    this->layout_Func = std::bind(
        [](__StackLayout *self)
        {
            if (self->layout_effect)
            {
                float old_y = self->y;
                float next_x = self->x;
                float next_y = self->y;
                size_t index = 0;
                for (auto &son : self->children)
                {
                    if (((self->ignore_height) ? next_y + 1 : next_y + son->height) > self->y + self->height)
                    {
                        if (self->remove_limit == false)
                        {
                            self->_remove_log(son);
                            continue;
                        }
                    }
                    else if (((self->ignore_width) ? next_x + 1 : next_x + son->width) > self->x + self->width)
                    {
                        next_x = self->x;
                        next_y = old_y;
                        if (index == 0)
                        {
                            self->_remove_log(son);
                            continue;
                        }
                        else if (((self->ignore_height) ? next_y + 1 : next_y + son->height) > self->y + self->height)
                        {
                            if (self->remove_limit == false)
                            {
                                self->_remove_log(son);
                                continue;
                            }
                        }
                    }
                    old_y = (old_y < son->y + son->height) ? son->y + son->height : old_y;
                    son->x = next_x;
                    son->y = next_y;
                    next_x += son->width;
                    son->setRect();
                    index++;
                }
            }
        },
        this);
}

void __StackLayout::__initVariables()
{
    this->ignore_width = false;
    this->ignore_height = false;
    this->remove_limit = false;
}
