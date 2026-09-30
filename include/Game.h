#pragma once
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include "Renderer.h"
#include "Input.h"

class Game {
private:
    Board board;
    Snake snake;
    Food food;
    Renderer renderer;
    Input input;

    bool running;
    bool dead;
    int score;
    int moveDelay;
    
    Point randomFoodPosition() const;
    bool isFoodEaten() const;
    bool isWallCollision() const;
    bool isSelfCollision() const;
    void clearScreen() const;
public:
    Game();
    void run();
    void gameOverScreen() const;
    
};