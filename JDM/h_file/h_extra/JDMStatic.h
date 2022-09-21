#pragma once
#include "__widget.h"

class Static
{
public:
    static float getWHalf(__Widget &widget) { return widget.get_whalf(); }
    static float getHHalf(__Widget &widget) { return widget.get_hhalf(); }
    static float getRight(__Widget &widget) { return widget.get_right(); }
    static float getBottom(__Widget &widget) { return widget.get_bottom(); }
    static float getCenterX(__Widget &widget) { return widget.get_right() - widget.get_whalf(); }
    static float getCenterY(__Widget &widget) { return widget.get_bottom() - widget.get_hhalf(); }
    static float retCenterX(__Widget &set, __Widget &widget) { return widget.get_center_x() - set.get_whalf(); }
    static float retCenterY(__Widget &set, __Widget &widget) { return widget.get_center_y() - set.get_hhalf(); }

    static void setCenterX(__Widget &set, __Widget &widget) { set.x = widget.get_center_x() - set.get_whalf(); }
    static void setCenterY(__Widget &set, __Widget &widget) { set.y = widget.get_center_y() - set.get_hhalf(); }

    static void setCenter(__Widget &set, __Widget &widget)
    {
        Static::setCenterX(set, widget);
        Static::setCenterY(set, widget);
    }
};
