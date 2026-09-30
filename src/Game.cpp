#include "Game.h"
#include <random>
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <windows.h>

Game::Game() 
    :board(20,10),
    score(0),
    dead(false),
    moveDelay(500),
    running(true){            
    food.setPosition(randomFoodPosition());
}   

Point Game::randomFoodPosition() const{
    static std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> xDist(0, board.getWidth() - 1);
    std::uniform_int_distribution<int> yDist(0, board.getHeight() - 1);

    while(true) {
        Point position{
            xDist(rng),
            yDist(rng)
        };

        bool onSnake=false;

        for(const Point& part:snake.getBody()) {
            if(part.x==position.x && part.y == position.y) {
                onSnake=true;
                break;
            }
        }
        if(!onSnake) {
            return position;
        }
    }
}

bool Game::isFoodEaten() const {
    return snake.getHead()==food.getPosition();
}

bool Game::isWallCollision() const {
    return !board.isInside(snake.getHead());
}

bool Game::isSelfCollision() const {
    Point head=snake.getHead();

    const auto& body=snake.getBody();

    for(size_t i=1;i<body.size();i++) {
        if(head==body[i]) {
            return true;
        }
    }
    return false;
}

void Game::gameOverScreen() const {
    clearScreen();

    std::cout << "====================\n";
    std::cout << "     GAME OVER\n";
    std::cout << "====================\n";
    std::cout << "Score: " << score << '\n';
}

void Game::clearScreen() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD position;
    position.X = 0;
    position.Y = 0;

    SetConsoleCursorPosition(hConsole, position);
}

void Game::run() {
    while (running) {

        if (_kbhit()) {
            int key = _getch();

            if (key == 'q' || key == 'Q') {
                running = false;
            }
            else if (key == 224) {
                key = _getch();

                if (key == 72) {
                    snake.changeDirection(Direction::Up);
                }
                else if (key == 80) {
                    snake.changeDirection(Direction::Down);
                }
                else if (key == 75) {
                    snake.changeDirection(Direction::Left);
                }
                else if (key == 77) {
                    snake.changeDirection(Direction::Right);
                }
            }
        }

        snake.move();

        if (isWallCollision()) {
            dead=true;
            running = false;
        }
        else if (isSelfCollision()) {
            dead=true;
            running = false;
        }
        else if (isFoodEaten()) {
            snake.grow();
            score++;
            if(moveDelay>100) {
                moveDelay-=20;
            }
            food.setPosition(randomFoodPosition());
        }

        clearScreen();
        std::cout << "Score: " << score << '\n';
        renderer.render(board, snake, food);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(moveDelay)
        );
    }
    if (dead) {
        gameOverScreen();
    }
}