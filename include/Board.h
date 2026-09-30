#pragma once
#include "Point.h"

class Board {
private:
    int width;
    int height;
public:
    Board(int width,int height);
    bool isInside(Point point) const;

    int getWidth() const;
    int getHeight() const;
};