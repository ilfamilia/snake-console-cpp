# Snake Game (Console – C++)

## Project Status
### Early Development / Work in Progress

This repository contains a console-based **Snake game** written in **C++**.
It is currently under development and **not a final version**.

The project is built incrementally to document:
- architecture decisions
- refactoring steps
- feature evolution over time


## Current Features

At this stage, the project includes:

- A configurable game board rendered in the Windows console
- Visible borders (walls) that define the playable area
- Snake head movement controlled with:
  - **W** → Up
  - **A** → Left
  - **S** → Down
  - **D** → Right
- Wall collision detection
- Automatic reset when a wall is hit
- Food entity rendered on the board (currently static)
- Clean rendering using cursor positioning to update only necessary cells.
- Modular multi-file project structure
- Build configuration using **CMake**

This version focuses on **core structure, rendering, and movement mechanics** rather than full gameplay.


## Project Structure

```text
snake-console-cpp/
├── CMakeLists.txt
├── include/
│   ├── Board.h
│   ├── Config.h
│   ├── Food.h
│   ├── Point.h
│   ├── Renderer.h
│   └── Snake.h
├── src/
│   ├── Board.cpp
│   ├── Food.cpp
│   ├── main.cpp
│   ├── Renderer.cpp
│   └── Snake.cpp
├── .gitignore
└── README.md
```

## Modules

- **Board**
Handles board dimensions and wall logic.

- **Snake**
Manages the snake position and movement.

- **Renderer**
Provides console drawing utilities such as cursor positioning, drawing the board borders, clearing cells, and hiding/showing the cursor.

- **Food**
Represents the food entity and its position on the board (currently static).

- **Point**
Centralized 2D coordinate structure reused across the project.

- **Config**
Centralized configuration for board size, symbols, and constants.

## Technologies Used

- C++ (C++17+)
- Windows Console API (windows.h)
- _kbhit() and _getch() for non-blocking keyboard input
- CMake for build configuration

**Note:** This project is currently Windows-only due to console-specific APIs.

## Planned Features (Future Work)

- Food respawn logic
- Snake body growth
- Score tracking
- Game-over state
- Game speed control (timing / game loop)
- Proper exit handling
- Cross-platform rendering (long-term goal)

## How to Build and Run
**Requirements**

- Windows
- CMake 3.16+
- A C++ compiler (MSVC or MinGW)

## Build
```bash
cmake -S . -B build
cmake --build build
```
## Run
```bash
./build/snake
```

(On Windows, the executable may be snake.exe depending on the generator.)

## License

This project is for educational purposes and personal learning.