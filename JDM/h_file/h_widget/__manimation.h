#pragma once

class __Animation
{
public:
    bool pauseAnimation = false;
    bool cancelAnimation = false;
    funcCallback startAnimation = []() {};
    funcCallback WhileAnimation = []() {};
    funcCallback endAnimation = []() {};

public:
    virtual bool _update() { return true; };
};
