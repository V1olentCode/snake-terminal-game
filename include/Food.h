#pragma once
#include "Point.h"

class Food {
private:
    Point position;
public:
    Food();

    Point getPosition() const;
    void setPosition(Point position);
};