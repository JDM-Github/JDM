#pragma once
#include <functional>

class __Animation
{
public:
    bool pauseAnimation = false;
    bool cancelAnimation = false;
    std::function<void()> startAnimation = []() {};
    std::function<void()> WhileAnimation = []() {};
    std::function<void()> endAnimation = []() {};

public:
    virtual bool _update() { return true; };
};
