#pragma once
#include "__widget.h"

class __MLayout : public __Widget
{
public:
    bool layout_effect;

public:
    __MLayout(const float width = 100.f, const float height = 100.f, const float x = 0.f, const float y = 0.f);

protected:
    void _remove_log(std::shared_ptr<__Widget> son);
};
