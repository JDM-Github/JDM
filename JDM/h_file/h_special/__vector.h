#pragma once
#include "__header.h"

class __Vector2F
{
public:
    float first, second;

public:
    constexpr __Vector2F(const float x, const float y) : first(x), second(y) {}

    __Vector2F operator+(const __Vector2F &vec) { return __Vector2F(this->first + vec.first, this->second + vec.second); }
    __Vector2F operator-(const __Vector2F &vec) { return __Vector2F(this->first - vec.first, this->second - vec.second); }
    __Vector2F operator/(const __Vector2F &vec) { return __Vector2F(this->first / vec.first, this->second / vec.second); }
    __Vector2F operator*(const __Vector2F &vec) { return __Vector2F(this->first * vec.first, this->second * vec.second); }

    __Vector2F operator+(std::array<float, 2> &arr) { return __Vector2F(this->first + arr[0], this->second + arr[1]); }
    __Vector2F operator-(std::array<float, 2> &arr) { return __Vector2F(this->first - arr[0], this->second - arr[1]); }
    __Vector2F operator/(std::array<float, 2> &arr) { return __Vector2F(this->first / arr[0], this->second / arr[1]); }
    __Vector2F operator*(std::array<float, 2> &arr) { return __Vector2F(this->first * arr[0], this->second * arr[1]); }
    __Vector2F &operator+=(const __Vector2F &vec)
    {
        this->operator=(this->operator+(vec));
        return *this;
    }
    __Vector2F &operator*=(const __Vector2F &vec)
    {
        this->operator=(this->operator*(vec));
        return *this;
    }
    __Vector2F &operator-=(const __Vector2F &vec)
    {
        this->operator=(this->operator-(vec));
        return *this;
    }
    __Vector2F &operator/=(const __Vector2F &vec)
    {
        this->operator=(this->operator/(vec));
        return *this;
    }
    __Vector2F &operator+=(std::array<float, 2> &arr)
    {
        this->operator=(this->operator+(arr));
        return *this;
    }
    __Vector2F &operator*=(std::array<float, 2> &arr)
    {
        this->operator=(this->operator*(arr));
        return *this;
    }
    __Vector2F &operator-=(std::array<float, 2> &arr)
    {
        this->operator=(this->operator-(arr));
        return *this;
    }
    __Vector2F &operator/=(std::array<float, 2> &arr)
    {
        this->operator=(this->operator/(arr));
        return *this;
    }
    float operator[](const size_t &index)
    {
        if (index > 1 || index < 0)
            return 0;
        return (index == 0) ? this->first : this->second;
    }
    bool operator==(const __Vector2F &vec) { return (this->first == vec.first && this->second == vec.second); }
    bool operator!=(const __Vector2F &vec) { return !this->operator==(vec); }
    bool operator<(const __Vector2F &vec) { return this->first + this->second < vec.first + vec.second; }
    bool operator>(const __Vector2F &vec) { return this->first + this->second > vec.first + vec.second; }
    bool operator<=(const __Vector2F &vec) { return this->first + this->second <= vec.first + vec.second; }
    bool operator>=(const __Vector2F &vec) { return this->first + this->second >= vec.first + vec.second; }
    __Vector2F &operator=(const __Vector2F &vec)
    {
        this->first = vec.first;
        this->second = vec.second;
        return *this;
    }
    __Vector2F &operator=(std::array<float, 2> arr)
    {
        this->first = arr[0];
        this->second = arr[1];
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &os, const __Vector2F &vec) { return os << "(" << vec.first << ", " << vec.second << ")"; }
    friend std::array<float, 2> operator+(std::array<float, 2> arr, const __Vector2F &vec) { return std::array<float, 2>{arr[0] + vec.first, arr[1] + vec.second}; }
    friend std::array<float, 2> operator*(std::array<float, 2> arr, const __Vector2F &vec) { return std::array<float, 2>{arr[0] * vec.first, arr[1] * vec.second}; }
    friend std::array<float, 2> operator-(std::array<float, 2> arr, const __Vector2F &vec) { return std::array<float, 2>{arr[0] - vec.first, arr[1] - vec.second}; }
    friend std::array<float, 2> operator/(std::array<float, 2> arr, const __Vector2F &vec) { return std::array<float, 2>{arr[0] / vec.first, arr[1] / vec.second}; }
};
