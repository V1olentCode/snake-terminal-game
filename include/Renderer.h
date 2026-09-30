#pragma once

#include "Board.h"
#include "Snake.h"
#include "Food.h"

class Renderer {
public:
    void render(const Board& board,const Snake& snake,const Food& food) const;
};