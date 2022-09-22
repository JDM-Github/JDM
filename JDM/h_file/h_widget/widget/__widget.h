#pragma once
#include "__mwidget.h"

class __Widget : public __MWidget, public std::enable_shared_from_this<__Widget>
{
public:
    __Widget *parent = nullptr;

    float size_hint_x;
    float size_hint_y;
    float velocity_x;
    float velocity_y;
    bool camera_related = false;

public:
    virtual void initObject() {}
    virtual void setRect() {}
    std::shared_ptr<__Widget> get_this() { return shared_from_this(); }
    __Widget(const float w = 100.f, const float h = 100.f, const float x_ = 0.f, const float y_ = 0.f);

    /* Add Widget */
    void add_widget(std::shared_ptr<__Widget> widg);
    void remove_widget(std::shared_ptr<__Widget> widg);
    std::list<std::shared_ptr<__Widget>> children;
    std::unordered_set<int> currentAnim;

protected:
    enum TypeLoop
    {
        UPDATE = 0,
        RENDER,
        L_M_DOWN,
        L_M_MOTION,
        L_M_UP,
        R_M_DOWN,
        R_M_MOTION,
        R_M_UP,
        ISLAYOUT
    };

protected:
    void _loopEvent(std::shared_ptr<__Widget> widg, __Widget::TypeLoop type);
    void _camera_update();
    void _back_camera();
    void _update();
    void _islayout();

private:
    float __width, __height, __x, __y;
    float __temp_camera_x;
    float __temp_camera_y;

private:
    void __update_position();
    void __initVariables();
    constexpr void __set_position()
    {
        if (this->is_layout == false)
        {
            if (this->size_in_parent)
            {
                this->width = (this->size_in_parent) ? this->parent->width * this->size_hint_x : this->width;
                this->height = (this->size_in_parent) ? this->parent->height * this->size_hint_y : this->height;
            }
            if (this->bind_in_parent || this->pos_in_parent)
            {
                this->x = (this->pos_in_parent) ? this->parent->x : this->__x + (this->parent->x - this->parent->__x);
                this->y = (this->pos_in_parent) ? this->parent->y : this->__y + (this->parent->y - this->parent->__y);
            }
        }
    }
};
