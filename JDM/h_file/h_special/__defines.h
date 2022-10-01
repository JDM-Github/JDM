#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <fstream>
#include <ctime>
#include <list>
#include <utility>
#include <cmath>

#define FG_BLACK "\033[30m"
#define FG_RED "\033[31m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_BLUE "\033[34m"
#define FG_MAGENTA "\033[35m"
#define FG_CYAN "\033[36m"
#define FG_WHITE "\033[37m"
#define FG_CLEAR "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define INVERSE "\033[7m"
#define _BOLD "\033[21m"
#define _UNDERLINE "\033[24m"
#define _INVERSE "\033[27m"

#define PI 3.14159265358979323846

#define XANIMATION 0x80
#define YANIMATION 0x81
#define WANIMATION 0x82
#define HANIMATION 0x83
#define MOVEANIMATION 0x100
#define SIZEANIMATION 0x101
#define ZOOMANIMATION 0x102
#define MOVESIZEANIMATION 0x103
#define RGBAANIMATION 0x110

inline void Log() { std::cout << std::endl; }
template <typename X, typename... Args>
inline void Log(const X &x, const Args... args)
{
    std::cout << x;
    Log(args...);
}
inline bool checkExist(const std::string &file = "None")
{
    std::ifstream ifile;
    ifile.open(file);
    return (ifile) ? true : false;
}
using funcCallback = std::function<void()>;
template <typename T>
using property = std::list<std::pair<std::pair<T, std::reference_wrapper<T>>, funcCallback>>;

inline bool operator==(const std::string &str, const std::string &str2) { return !(str.compare(str2)); }
inline bool operator!=(const std::string &str, const std::string &str2) { return (str.compare(str2)); }
template <typename T, size_t S>
inline std::ostream &operator<<(std::ostream &os, const std::array<T, S> &arr)
{
    for (auto ar : arr)
        os << ar << " ";
    return os;
}
