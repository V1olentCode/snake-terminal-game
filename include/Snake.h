#pragma once

#include <deque>
#include "Point.h"

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

class Snake {
private:
    std::deque<Point> body;
    Direction direction;
    Direction nextDirection;
public:
    Snake();
    void move();
    void grow();
    void changeDirection(Direction newDirection);

    Point getHead() const;
    const std::deque<Point>& getBody() const;
    Point nextHead() const;
};