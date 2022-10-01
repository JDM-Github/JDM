#pragma once

class Collision
{
public:
    static bool CircleRectCollision(const float circleX, const float circleY,
                                    const float circleRadius, const float rectX, const float rectY,
                                    const float rectWidth, const float rectHeight);
    static bool CircleCircleCollision(const float circleX1, const float circleY1, const float circleRadius1,
                                      const float circleX2, const float circleY2, const float circleRadius2);
    static bool RectRectCollision(const float rectX1, const float rectY1,
                                  const float rectWidth1, const float rectHeight1,
                                  const float rectX2, const float rectY2,
                                  const float rectWidth2, const float rectHeight2);
    static bool LineLineCollision(const float l1x1, const float l1y1, const float l1x2, const float l1y2,
                                  const float l2x1, const float l2y1, const float l2x2, const float l2y2);

    static bool getLineLineCollision(const float l1x1, const float l1y1, const float l1x2, const float l1y2,
                                     const float l2x1, const float l2y1, const float l2x2, const float l2y2,
                                     float &lineIntersectionX, float &lineIntersectionY);
    static bool LineRectCollision(const float lx1, const float ly1, const float lx2, const float ly2,
                                  const float rectX, const float rectY, const float rectWidth, const float rectHeight);

private:
};
