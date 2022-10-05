#pragma once
#include "__header.h"

namespace JDM
{
    extern void stringAppend(std::string &storage, bool separator);
    template <typename First, typename... Args>
    void stringAppend(std::string &storage, bool separator, First value, Args... args)
    {
        std::stringstream str;
        str << value;
        std::string temp;
        while (str >> temp)
            storage.append(temp + " ");
        if (!separator)
            storage.erase(storage.size() - 1);
        JDM::stringAppend(storage, separator, args...);
    }
    template <typename First, typename... Args>
    std::string getString(bool separator, First value, Args... args)
    {
        std::string storage;
        JDM::stringAppend(storage, separator, value, args...);
        return storage;
    }
    template <typename T>
    constexpr T randomRange(const double first, const double second)
    {
        if (first >= second)
            return static_cast<T>(first);
        return static_cast<T>(first + ((static_cast<double>(rand()) / static_cast<double>(RAND_MAX)) * (second - first)));
    }
    template <typename T>
    constexpr T negative(T &value) { return (value > 0) ? value * -1 : value; }
    template <typename T>
    constexpr T positive(T &value) { return (value < 0) ? value * -1 : value; }
    template <typename T>
    constexpr T changeSign(T &value) { return value * -1; }
}
