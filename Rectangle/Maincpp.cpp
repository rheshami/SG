#include <iostream>
#include <memory>
#include "Rectangle2D.h"

void printPointTest(bool result, const Point& point)
{
    const char* isIn = ") is";
    if (!result)
        isIn = ") is not";

    std::cout << "Point (" << point.X << "," << point.Y << isIn << " in the rectangle." << std::endl;

}


void printCollisionTest(bool result)
{
    const char* collide = " colliding.";
    if (!result)
        collide = " not colliding.";

    std::cout << "Rectangles are " << collide << std::endl;

}

int main()
{
    Point startPoint;
    std::unique_ptr<Rectangle2D> recAA(new Rectangle2D({ 10.0f , 11.0f },10,5));

    Point p1 = { 2,5 };
    printPointTest(recAA->isInRectangle(p1),p1);

    p1 = { 12, 14 };
    printPointTest(recAA->isInRectangle(p1), p1);

    std::unique_ptr<Rectangle2D> rectangle2(new Rectangle2D({ 21.0f , 21.0f }, 2, 2));
    printCollisionTest(recAA->isColliding(*rectangle2));

    std::unique_ptr<Rectangle2D> rectangle3(new Rectangle2D({ 12.0f , 21.0f }, 2, 2));
    printCollisionTest(recAA->isColliding(*rectangle3));

    std::unique_ptr<Rectangle2D> rectangle4(new Rectangle2D({ 5.0f , 5.0f }, 10, 8));
    printCollisionTest(recAA->isColliding(*rectangle4));
}

