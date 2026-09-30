#include "Input.h"
#include <conio.h>

bool Input::process(Direction& direction) {

    if (!_kbhit()) {
        return true;
    }

    int key = _getch();
    if (key == 224) {
        key = _getch();

        if (key == 72) {
            direction = Direction::Up;
        }
        else if (key == 80) {
            direction = Direction::Down;
        }
        else if (key == 75) {
            direction = Direction::Left;
        }
        else if (key == 77) {
            direction = Direction::Right;
        }
    }
    else if (key == 'w' || key == 'W') {
        direction = Direction::Up;
    }
    else if (key == 's' || key == 'S') {
        direction = Direction::Down;
    }
    else if (key == 'a' || key == 'A') {
        direction = Direction::Left;
    }
    else if (key == 'd' || key == 'D') {
        direction = Direction::Right;
    }
    else if (key == 'q' || key == 'Q') {
        return false;
    }
    return true;
}