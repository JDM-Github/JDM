#include "JDM.h"

__GridLayout::__GridLayout(const int _row, const int _col,
                           const float width, const float height,
                           const float x, const float y)
    : row(_row), col(_col), __MLayout(width, height, x, y)
{
    this->__initVariables();
    this->layout_Func = std::bind(
        [](__GridLayout *self)
        {
            self->__set_children_size();
            if (self->layout_effect)
            {
                int __row = 0, __col = 0;
                for (auto &son : self->children)
                {
                    if (__col >= self->col)
                    {
                        __row++;
                        if (__row == self->row)
                        {
                            self->_remove_log(son);
                            continue;
                        }
                        __col = 0;
                    }
                    son->width = self->children_width;
                    son->height = self->children_height;
                    son->x = self->x + self->padding_x + (self->children_width * __col) + (self->spacing_x * __col);
                    son->y = self->y + self->padding_y + (self->children_height * __row) + (self->spacing_y * __row);
                    son->setRect();
                    __col++;
                }
            }
        },
        this);
}

void __GridLayout::__initVariables()
{
    this->__c_width = 0.f;
    this->__c_height = 0.f;
    this->layout_effect = true;
    this->padding_x = 0.f;
    this->padding_y = 0.f;
    this->spacing_x = 1.f;
    this->spacing_y = 1.f;
    this->__set_children_size();
}

void __GridLayout::__set_children_size()
{
    this->children_width = (((this->width - (this->spacing_x * (this->col - 1))) - (this->padding_x * 2)) / this->col);
    if (JDM::enable_log)
        if (this->children_width <= 0 && this->__c_width != this->children_width)
        {
            this->__c_width = this->children_width;
            if (JDM::enable_color)
                Log(FG_YELLOW, "Note", FG_CLEAR, ": ", FG_GREEN, "GridLayout", FG_CLEAR, " - ",
                    FG_CYAN, this, FG_CLEAR, " Children Width is too small.\n - Children Width: ",
                    FG_GREEN, this->children_width, FG_CLEAR);
            else
                Log("Note: GridLayout - ", this, " Children Width is too small.\n - Children Width: ",
                    this->children_width);
        }
    this->children_height = (((this->height - (this->spacing_y * (this->row - 1))) - (this->padding_y * 2)) / this->row);
    if (JDM::enable_log)
        if (this->children_height <= 0 && this->__c_height != this->children_height)
        {
            this->__c_height = this->children_height;
            if (JDM::enable_color)
                Log(FG_YELLOW, "Note", FG_CLEAR, ": ", FG_GREEN, "GridLayout", FG_CLEAR, " - ",
                    FG_CYAN, this, FG_CLEAR, " Children Height is too small.\n - Children Height: ",
                    FG_GREEN, this->children_height, FG_CLEAR);
            else
                Log("Note: GridLayout - ", this, " Children Height is too small.\n - Children Height: ",
                    this->children_height);
        }
}

void __GridLayout::_update()
{
    this->_camera_update();
    __Widget::_update();
}

void __GridLayout::add_widget(std::shared_ptr<__Widget> widg)
{
    if (this->children.size() < (this->col * this->row))
    {
        this->children.emplace_back(widg);
        widg->parent = this;
        return;
    }
    if (JDM::enable_log)
        if (JDM::enable_color)
            Log(FG_YELLOW, "Note", FG_CLEAR, ": ", FG_GREEN, "GridLayout", FG_CLEAR, " - ",
                FG_CYAN, this, FG_CLEAR, " is full!\n - To add more ", FG_GREEN, "Widget", FG_CLEAR, ", Increase Rows/Cols.");
        else
            Log("Note: GridLayout - ", this, " is full!\n - To add more Widget, Increase Rows/Cols.");
}
