#ifndef SNAKE_H
#define SNAKE_H

#include "Point.h"
#include "Direction.h"

// Represents the snake entity in the game.
// At this stage, the snake is modeled as a single segment with
// its current position and previous position.
class Snake {
public:
    // Creates a snake at the given initial position.
    Snake(int posX, int posY);

    // Resets the snake position to the given coordinates.
    // Also updates the previous position accordingly.
    void resetPos(int posX, int posY);

    // Returns the current position of the snake.
    Point getPos() const;

    // Returns the previous position of the snake.
    // Useful for clearing the old character from the screen.
    Point getOldPos() const;

    Point peekNextPos() const;

    void setDirection(Direction dir);

    // Moves the snake one cell
    void move();

private:
    // Current position of the snake.
    Point pos_;

    // Previous position of the snake (before the last move).
    Point oldPos_;

    Direction currentDir_;

    Point delta() const;
};

#endif // SNAKE_H
