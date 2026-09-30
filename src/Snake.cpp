#include "Snake.h"  

Snake::Snake(){
    direction=Direction::Right;
    nextDirection = Direction::Right;
    body.push_back({5,5});
    body.push_back({4,5});
    body.push_back({3,5});
}

Point Snake::getHead() const{
    return body.front();
}

const std::deque<Point>& Snake::getBody() const{
    return body;
}

Point Snake::nextHead() const {
    Point newHead=body.front();
    
    if(nextDirection==Direction::Up) {
        newHead.y--;
    }
    else if(nextDirection==Direction::Down) {
        newHead.y++;
    }
    else if(nextDirection==Direction::Left) {
        newHead.x--;
    }
    else if(nextDirection==Direction::Right) {
        newHead.x++;
    }
    return newHead;
}

void Snake::move() {
    direction = nextDirection;
    Point newHead=nextHead();
    body.push_front(newHead);
    body.pop_back();
}

void Snake::grow() {
    direction = nextDirection;
    Point newHead=nextHead();
    body.push_front(newHead);
}

void Snake::changeDirection(Direction newDirection) {
    if (direction==Direction::Up &&
        newDirection==Direction::Down) {
        return;
    }
    if (direction==Direction::Down &&
        newDirection==Direction::Up) {
        return;
    }
    if (direction==Direction::Left &&
        newDirection==Direction::Right) {
        return;
    }
    if (direction==Direction::Right &&
        newDirection==Direction::Left) {
        return;
    }
    nextDirection = newDirection;
}

