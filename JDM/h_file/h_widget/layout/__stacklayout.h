#pragma once
#include "__mlayout.h"

class __StackLayout : public __MLayout
{
public:
    bool ignore_width;
    bool ignore_height;
    bool remove_limit;

public:
    __StackLayout(const float width = 100.f, const float hieght = 100.f,
                  const float x = 0.f, const float y = 0.f);

private:
    void __initVariables();
};