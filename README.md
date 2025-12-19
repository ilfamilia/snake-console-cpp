# Snake Game (Console – C++)

## Project Status  
### Early Development / Initial Commit

This repository contains an early version of a console-based **Snake game** written in **C++**.  
This is **not the final version** of the project.

The purpose of this commit is to document the **first significant milestone**:  
the creation of a playable board and a controllable character that moves within it.

---

## Current Features

At this stage, the project includes:

- A configurable game board rendered in the Windows console  
- Visible borders (walls) that define the playable area  
- A player character rendered on the board  
- Keyboard-controlled movement using:
  - **W** → Up  
  - **A** → Left  
  - **S** → Down  
  - **D** → Right  
- Wall collision detection  
- Automatic reset of the player position when a wall is hit  
- Clean rendering using cursor positioning (no full-screen redraw per frame)

This version focuses on **core structure and movement mechanics rather than full gameplay**.

---

## Project Structure

The project is organized using clear separation of responsibilities:

- **Board**  
  Handles board dimensions, walls, and playable area logic.

- **Snake**  
  Manages the player position and movement.

- **Renderer**  
  Responsible for all console rendering and cursor control.

- **Config**  
  Centralized configuration for board size and rendering characters.

This structure is intentionally designed to allow **easy extension** in future versions.

---

## Technologies Used

- **C++ (C++17+)**
- Windows Console API (`windows.h`)
- `_kbhit()` and `_getch()` for non-blocking keyboard input

>**Note:** This project is currently **Windows-only** due to console-specific APIs.

---

## Planned Features (Future Work)

The following features are planned for future commits:

- Snake body growth  
- Food generation  
- Score tracking  
- Game-over state  
- Game speed control (timing / game loop)  
- Proper exit handling  
- Cross-platform rendering (possible future goal)

Each major improvement will be committed incrementally to reflect learning progress.

---

## Purpose of This Repository

This project is part of my **learning process in C++ and game development fundamentals**.  
Commits are intentionally incremental to reflect:

- Design decisions  
- Refactoring steps  
- Feature evolution over time  

This repository serves both as a **portfolio project** and a **personal learning log**.

---

## How to Run

1. Clone the repository  
2. Compile using a C++ compiler on Windows (e.g. **MSVC** or **MinGW**)  
3. Run the executable in a Windows console  
4. Use **W, A, S, D** to move the character  

---

## License

This project is for **educational purposes**.
