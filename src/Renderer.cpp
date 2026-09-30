#include "Renderer.h"
#include <iostream>

void Renderer::render(const Board& board,const Snake& snake,const Food& food) const {
    std::cout << '+';
    for(int x=0;x<board.getWidth();x++) {
        std::cout << '-';
    }
    std::cout << "+\n";
    for(int y=0;y<board.getHeight();y++) {
        std::cout << '|';
        for(int x=0;x<board.getWidth();x++) {
            bool isSnake=false;
            for(const Point& part:snake.getBody()) {
                if(part.x==x && part.y==y) {
                    isSnake=true;
                    break;
                }
            }
            bool isFood =
                food.getPosition().x == x && 
                food.getPosition().y == y;

            if(isSnake) {
                std::cout << '#';
            }
            else if(isFood) {
                std::cout << '*';
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << "|\n";
    }
    std::cout << '+';
    for(int x=0;x<board.getWidth();x++) {
        std::cout << '-';
    }
    std::cout << "+\n";
}