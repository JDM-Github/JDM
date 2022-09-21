#include "JDM.h"

__MLayout::__MLayout(const float width, const float height, const float x, const float y) : __Widget(width, height, x, y)
{
    this->layout_effect = true;
    this->is_layout = true;
}

void __MLayout::_remove_log(std::shared_ptr<__Widget> son)
{
    if (JDM::enable_log)
        if (JDM::enable_color)
            Log(FG_YELLOW, "Attention", FG_CLEAR, ": ",
                FG_GREEN, "Widget", FG_CLEAR, " - ", FG_CYAN, son, FG_CLEAR, " has been ",
                FG_RED, "removed", FG_CLEAR, "!");
        else
            Log("Attention: Widget - ", son, " has been removed!");
    this->remove_widget(son);
}
