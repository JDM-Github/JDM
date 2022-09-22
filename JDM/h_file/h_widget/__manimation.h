#pragma once

class __Animation
{
public:
    bool pauseAnimation = false;

public:
    virtual bool _update() { return true; };
};
