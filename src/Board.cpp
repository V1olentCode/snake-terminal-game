#include "Board.h"

Board::Board(int width,int height) {
    this->width=width;
    this->height=height;
}

bool Board::isInside(Point point) const{
    return (point.x>=0) &&
           (point.y>=0) &&
           (point.y<height) &&
           (point.x<width);
}

int Board::getHeight() const{
    return height;
}

int Board::getWidth() const{
    return width;
}