#include "JDMAlgorithm.h"
#include "JDM.h"

float Algorithm::getAngle(float x1, float y1, float x2, float y2)
{
    return Algorithm::RadtoDeg(std::atan2(y2 - y1, x2 - x1));
}

bool Algorithm::pythagoreamTheorem(const float X, const float Y, const float Compare)
{
    return (((X * X) + (Y * Y)) <= Compare * Compare);
}

void Algorithm::calculateScope(float x1, float y1, float x2, float y2, float &dx, float &dy)
{
    float step = std::max(std::abs(x1 - x2), std::abs(y1 - y2));
    if (step == 0)
    {
        dx = dy = 0;
        return;
    }
    dx = (x1 - x2);
    dx /= step;
    dy = (y1 - y2);
    dy /= step;
}

float Algorithm::DegtoRad(float degree)
{
    return degree * (PI / 180);
}

float Algorithm::RadtoDeg(float radian)
{
    return radian * (180 / PI);
}

float Algorithm::followMouse(float widX, float widY, float width, float height)
{
    return Algorithm::getAngle(widX + (width / 2), widY + (height / 2), JDM::mouseX, JDM::mouseY) + 90;
}
