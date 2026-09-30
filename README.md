# Terminal Snake Game

A terminal-based Snake game written in C++ using object-oriented programming and CMake.

## Features

- Arrow key and WASD controls
- Random food generation
- Snake growth
- Wall collision detection
- Self-collision detection
- Score tracking
- Increasing game speed
- Game-over screen

## Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| A / ← | Move Left |
| S / ↓ | Move Down |
| D / → | Move Right |
| Q | Quit |

## Project Structure

```text
terminal-snake/
├── include/
│   ├── Board.h
│   ├── Food.h
│   ├── Game.h
│   ├── Input.h
│   ├── Point.h
│   ├── Renderer.h
│   └── Snake.h
├── src/
│   ├── Board.cpp
│   ├── Food.cpp
│   ├── Game.cpp
│   ├── Input.cpp
│   ├── Renderer.cpp
│   ├── Snake.cpp
│   └── main.cpp
├── CMakeLists.txt
├── .gitignore
└── README.md