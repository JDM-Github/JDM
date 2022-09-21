#include "JDMCollision.h"

bool Collision::CircleRectCollision(const float circleX, const float circleY,
                                    const float circleRadius, const float rectX, const float rectY,
                                    const float rectWidth, const float rectHeight)
{
    float testX = circleX;
    float testY = circleY;

    // Test RIGHT-LEFT edges
    if (circleX < rectX)
        testX = rectX;
    else if (circleX > rectX + rectWidth)
        testX = rectX + rectWidth;

    // Test UP-BOTTOM edges
    if (circleY < rectY)
        testY = rectY;
    else if (circleY > rectY + rectHeight)
        testY = rectY + rectHeight;

    float distX = circleX - testX;
    float distY = circleY - testY;

    // Pythagoream Theorem
    return Collision::pythagoreamTheorem(distX, distY, circleRadius);
}

bool Collision::pythagoreamTheorem(const float X, const float Y, const float Compare)
{
    if (((X * X) + (Y * Y)) <= Compare * Compare)
        return true;
    return false;
}

bool Collision::CircleCircleCollision(const float circleX1, const float circleY1, const float circleRadius1,
                                      const float circleX2, const float circleY2, const float circleRadius2)
{
    float distX = circleX1 - circleX2;
    float distY = circleY1 - circleY2;
    // Pythagoream Theoream
    return Collision::pythagoreamTheorem(distX, distY, circleRadius1 + circleRadius2);
}

bool Collision::RectRectCollision(const float rectX1, const float rectY1,
                                  const float rectWidth1, const float rectHeight1,
                                  const float rectX2, const float rectY2,
                                  const float rectWidth2, const float rectHeight2)
{
    if (rectX1 + rectWidth1 < rectX2)
        return false;
    if (rectX1 > rectX2 + rectWidth2)
        return false;
    if (rectY1 + rectHeight1 < rectY2)
        return false;
    if (rectY1 > rectY2 + rectHeight2)
        return false;
    return true;
}

bool Collision::LineLineCollision(const float l1x1, const float l1y1, const float l1x2, const float l1y2,
                                  const float l2x1, const float l2y1, const float l2x2, const float l2y2)
{
    float uA = ((l2x2 - l2x1) * (l1y1 - l2y1) - (l2y2 - l2y1) * (l1x1 - l2x1)) / ((l2y2 - l2y1) * (l1x2 - l1x1) - (l2x2 - l2x1) * (l1y2 - l1y1));
    float uB = ((l1x2 - l1x1) * (l1y1 - l2y1) - (l1y2 - l1y1) * (l1x1 - l2x1)) / ((l2y2 - l2y1) * (l1x2 - l1x1) - (l2x2 - l2x1) * (l1y2 - l1y1));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
        return true;
    return false;
}

bool Collision::getLineLineCollision(const float l1x1, const float l1y1, const float l1x2, const float l1y2,
                                     const float l2x1, const float l2y1, const float l2x2, const float l2y2,
                                     float &lineIntersectionX, float &lineIntersectionY)
{
    float uA = ((l2x2 - l2x1) * (l1y1 - l2y1) - (l2y2 - l2y1) * (l1x1 - l2x1)) / ((l2y2 - l2y1) * (l1x2 - l1x1) - (l2x2 - l2x1) * (l1y2 - l1y1));
    float uB = ((l1x2 - l1x1) * (l1y1 - l2y1) - (l1y2 - l1y1) * (l1x1 - l2x1)) / ((l2y2 - l2y1) * (l1x2 - l1x1) - (l2x2 - l2x1) * (l1y2 - l1y1));

    if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
    {
        lineIntersectionX = l1x1 + (uA * (l1x2 - l1x1));
        lineIntersectionY = l1y1 + (uA * (l1y2 - l1y1));
        return true;
    }
    return false;
}

bool Collision::LineRectCollision(const float lx1, const float ly1, const float lx2, const float ly2,
                                  const float rectX, const float rectY, const float rectWidth, const float rectHeight)
{
    if (Collision::LineLineCollision(lx1, ly1, lx2, ly2, rectX, rectY, rectX + rectWidth, rectY) ||
        Collision::LineLineCollision(lx1, ly1, lx2, ly2, rectX, rectY, rectX, rectY + rectHeight) ||
        Collision::LineLineCollision(lx1, ly1, lx2, ly2, rectX + rectWidth, rectY, rectX + rectWidth, rectY + rectHeight) ||
        Collision::LineLineCollision(lx1, ly1, lx2, ly2, rectX, rectY + rectHeight, rectX + rectWidth, rectY + rectHeight))
        return true;
    return false;
}
