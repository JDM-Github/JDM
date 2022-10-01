#pragma once

class Algorithm
{
public:
    static float getAngle(float x1, float y1, float x2, float y2);
    static bool pythagoreamTheorem(const float X, const float Y, const float Compare);
    static void calculateScope(float x1, float y1, float x2, float y2, float &dx, float &dy);
    static float DegtoRad(float degree);
    static float RadtoDeg(float radian);

    static float followMouse(float widX, float widY, float width, float height);
};
