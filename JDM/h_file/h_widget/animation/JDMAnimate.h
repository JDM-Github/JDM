#pragma once
#include "__widget.h"
#include "JDMFps.h"
#include "__manimation.h"

class JDMAnimate
{
public:
    template <typename T>
    static bool Animate(const float adder, float &stopper, float &start,
                        const T end, __Widget *widg, __Animation *anim, T &target,
                        const int FLAG, const std::function<void()> &func)
    {
        if (anim->flag == false)
            return false;
        else if (anim->pauseAnimation)
            return true;
        else if (anim->cancelAnimation)
            return false;
        else if (widg->parent == nullptr)
            return true;

        stopper -= std::abs(adder);
        if (stopper <= 0)
        {
            anim->endAnimation();
            target = end;
            func();
            widg->currentAnim.erase(FLAG);
            return false;
        }
        start -= adder;
        target = static_cast<T>(start);
        anim->WhileAnimation();
        func();
        return true;
    }

    template <typename T, size_t S>
    static bool setAnimate(const std::array<float, S> &adder, std::array<float, S> &stopper,
                           std::array<float, S> &start, const std::array<T, S> &end,
                           __Widget *widg, __Animation *anim,
                           std::array<T *, S> &target, const int FLAG, const std::function<void()> &func)
    {
        if (anim->flag == false)
            return false;
        else if (anim->pauseAnimation)
            return true;
        else if (anim->cancelAnimation)
            return false;
        else if (widg->parent == nullptr)
            return true;

        Uint8 check = 0;
        for (Uint8 i = 0; i < S; i++)
        {
            stopper[i] -= std::abs(adder[i]);
            if (stopper[i] <= 0)
                check++;
        }

        if (check >= S)
        {
            anim->endAnimation();
            for (Uint8 i = 0; i < S; i++)
                *target[i] = end[i];
            func();
            widg->currentAnim.erase(FLAG);
            return false;
        }
        for (Uint8 i = 0; i < S; i++)
        {
            if (!(stopper[i] <= 0))
                start[i] -= adder[i];
            else
                start[i] = end[i];
            *target[i] = static_cast<T>(start[i]);
        }
        anim->WhileAnimation();
        func();
        return true;
    }

    template <typename T>
    static void initVariable(__Widget *widget, bool &flag, int TFLAG, T *target,
                             float &adder, float &start, float &stopper, T end, const float timer)
    {
        if (widget->currentAnim.find(TFLAG) != widget->currentAnim.end())
            flag = false;
        else
        {
            start = *target;
            adder = (start - end) * (1.0 / (timer * 60));
            stopper = std::abs(start - end);
        }
    }

    template <typename T, size_t S>
    static void initVariables(__Widget *widget, bool &flag, int TFLAG, std::array<T *, S> &target,
                              std::array<float, S> &adder, std::array<float, S> &start,
                              std::array<float, S> &stopper, std::array<T, S> &end,
                              std::array<T, S> ender, std::array<float, S> timer)
    {
        if (widget->currentAnim.find(TFLAG) != widget->currentAnim.end())
            flag = false;
        else
        {
            for (Uint8 i = 0; i < S; i++)
            {
                end[i] = ender[i];
                start[i] = *target[i];
                adder[i] = (start[i] - end[i]) * (1.0 / (timer[i] * 60));
                stopper[i] = std::abs(start[i] - end[i]);
            }
        }
    }
};
