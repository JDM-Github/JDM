#pragma once
#include <functional>
#include "__widgetcolor.h"

class __Animation
{
public:
    bool flag = true;
    bool pauseAnimation = false;
    bool cancelAnimation = false;
    std::function<void()> startAnimation = []() {};
    std::function<void()> WhileAnimation = []() {};
    std::function<void()> endAnimation = []() {};

public:
    virtual bool _update() { return true; };
};

class __ColorAnimation : public __Animation
{
public:
    const int TFLAG;
    __WidgetColor *widget;

    Uint8 *target;
    Uint8 end;
    float start;
    float adder;
    float stopper;

public:
    __ColorAnimation(std::shared_ptr<__Widget> widg, const Uint8 End, const int FLAG = 0);
    bool _update();
};

class __InitAnimation : public __Animation
{
protected:
    const int TFLAG;
    __Widget *widget;

    float *target;
    float end;
    float start;
    float adder;
    float stopper;

public:
    __InitAnimation(std::shared_ptr<__Widget> widg, const float End, const int FLAG = 0);
    bool _update();
};

// template <typename T, size_t S>
// class __InitSetAnimation : public __Animation
// {

// protected:
//     __Widget *widget;
//     std::array<T, S> end;
//     std::array<T *, S> target;
//     std::array<float, S> start;
//     std::array<float, S> adder;
//     std::array<float, S> stopper;

// public:
//     const std::array<T, S> old;

//     __InitSetAnimation()
// };
