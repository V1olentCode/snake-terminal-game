#include "Food.h"

Food::Food() {
    position={0,0};
}

Point Food::getPosition() const{
    return position;
}

void Food::setPosition(Point position) {
    this->position=position;
}
