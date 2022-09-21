#pragma once

struct __ColorManager
{
    template <typename T>
    static void __SetRandomColorA(T &r, T &g, T &b, T &a)
    {
        __ColorManager::__SetRandomColor(r, g, b);
        __ColorManager::__SetRandomRGBA(a);
    }
    template <typename T>
    static void __SetRandomColor(T &r, T &g, T &b)
    {
        __ColorManager::__SetRandomRGBA(r);
        __ColorManager::__SetRandomRGBA(g);
        __ColorManager::__SetRandomRGBA(b);
    }

    template <typename T>
    static void __SetRandomRGBA(T &rgba)
    {
        rgba = rand() % 256;
    }
};