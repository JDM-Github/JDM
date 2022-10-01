#pragma once
#include "__vector.h"

class __MWidget
{
public:
    /* Update Function:
     * -> Activate when widget update.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback updateFunc = []() {};
    /* Left Mouse Down Function:
     * -> Activate when left mouse is down.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback l_m_down_Func = []() {};
    /* Left Mouse Motion Function:
     * -> Activate when left mouse is in motion.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback l_m_motion_Func = []() {};
    /* Left Mouse Up Function:
     * -> Activate when left mouse is down then up.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback l_m_up_Func = []() {};
    /* Right Mouse Down Function:
     * -> Activate when right mouse is down.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback r_m_down_Func = []() {};
    /* Right Mouse Down Function:
     * -> Activate when right mouse is in motion.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback r_m_motion_Func = []() {};
    /* Right Mouse Up Function:
     * -> Activate when left mouse is down then up.
     * -> Use to update Widget without overriding a method.
     *
     * How to use?:
     * -> Widget->funcCallback = std::bind( std::function<void>, arguments... )
     */
    funcCallback r_m_up_Func = []() {};

    /**
     * Layout Function
     * ->
     *
     *
     */
    funcCallback layout_Func = []() {};

    float width, height, x, y;
    bool camera_related = false;
    bool bind_in_parent = false;
    bool size_in_parent = false;
    bool pos_in_parent = false;
    bool is_layout = false;

public:
    // Mother Widget: Collide Point
    // @param float,float
    constexpr bool collide_point(float x_, float y_) const { return (this->x <= x_ && x_ <= this->x + this->width &&
                                                                     this->y <= y_ && y_ <= this->y + this->height); }
    constexpr bool collide_widget(const __MWidget &widget) const
    {
        if (this->x + this->width < widget.x)
            return false;
        if (this->x > widget.x + widget.width)
            return false;
        if (this->y + this->height < widget.y)
            return false;
        if (this->y > widget.y + widget.height)
            return false;
        return true;
    }

    // @return -> Half Width of Widget
    constexpr float get_whalf() const { return this->width / 2; }

    // @return -> Half Height of Widget
    constexpr float get_hhalf() const { return this->height / 2; }

    // @return -> Widget Right
    constexpr float get_right() const { return this->x + this->width; }

    // @return -> Widget Bottom
    constexpr float get_bottom() const { return this->y + this->height; }

    // @return -> CenterX of Widget
    constexpr float get_center_x() const { return this->get_right() - this->get_whalf(); }

    // @return -> CenterY of Widget
    constexpr float get_center_y() const { return this->get_bottom() - this->get_hhalf(); }

protected:
    // Render Function.
    virtual void _render() {}

    // Update Function.
    virtual void _update() { this->updateFunc(); }

    // Left Mouse Down Function.
    virtual void _l_m_down() { this->l_m_down_Func(); }

    // Left Mouse Motion Function.
    virtual void _l_m_motion() { this->l_m_motion_Func(); }

    // Left Mouse Up Function.
    virtual void _l_m_up() { this->l_m_up_Func(); }

    // Right Mouse Down Function.
    virtual void _r_m_down() { this->r_m_down_Func(); }

    // Right Mouse Motion Function.
    virtual void _r_m_motion() { this->r_m_motion_Func(); }

    // Right Mouse Up Function.
    virtual void _r_m_up() { this->r_m_up_Func(); }

    // Is a Layout Function.
    virtual void _islayout() {}
};
