#pragma once
#include "__mlayout.h"

class __GridLayout : public __MLayout
{
private:
    float __c_width, __c_height;

private:
    void __set_children_size();
    void __initVariables();

public:
    int row, col;
    float padding_x;
    float padding_y;
    float spacing_x;
    float spacing_y;
    float children_width;
    float children_height;

public:
    __GridLayout(const int row = 1, const int col = 1,
                 const float width = 100.f, const float height = 100.f,
                 const float x = 0.f, const float y = 0.f);
    void add_widget(std::shared_ptr<__Widget> widg);

protected:
    void _update();
};